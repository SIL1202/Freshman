#include <iostream>

class Gate {
public:
  Gate *input[2];
  virtual bool output() = 0;
  void setValue(Gate *gate, int pin);
  void setValue(bool val, int pin);
};

class TRUE : public Gate {
public:
  virtual bool output() { return true; }
  void setValue(Gate *, int) {}
  void setValue(bool, int) {}
};

class FALSE : public Gate {
public:
  virtual bool output() { return false; }
  void setValue(Gate *, int) {}
  void setValue(bool, int) {}
};

TRUE t;
FALSE f;

void Gate::setValue(bool val, int pin) {
  if (val)
    this->input[pin] = &t;
  else
    this->input[pin] = &f;
}

void Gate::setValue(Gate *gate, int pin) { this->input[pin] = gate; }

class NOT : public Gate {
public:
  virtual bool output() { return !(this->input[0]->output()); }
  void setValue(bool val, int pin = 0) {
    if (val)
      this->input[0] = &t;
    else
      this->input[0] = &f;
  }
  void setValue(Gate *gate, int pin = 0) { this->input[0] = gate; }
};

class NAND : public Gate {
public:
  virtual bool output() {
    return !(this->input[0]->output() && this->input[1]->output());
  }
};

class NOR : public Gate {
public:
  virtual bool output() {
    return !(this->input[0]->output() || this->input[1]->output());
  }
};

class AND : public Gate {
public:
  AND() {
    component[0] = new NAND();
    component[1] = new NOT();
  }

  virtual bool output() {
    component[0]->input[0] = this->input[0];
    component[0]->input[1] = this->input[1];
    component[1]->input[0] = component[0];
    return component[1]->output();
  }

private:
  Gate *component[2];
};

class OR : public Gate {
public:
  OR() {
    component[0] = new NOR();
    component[1] = new NOT();
  }

  virtual bool output() {
    component[0]->input[0] = this->input[0];
    component[0]->input[1] = this->input[1];
    component[1]->input[0] = component[0];
    return component[1]->output();
  }

private:
  Gate *component[2];
};

class XOR : public Gate {
public:
  XOR() {
    component[0] = new AND();
    component[1] = new AND();
    component[2] = new NOT();
    component[3] = new NOT();
    component[4] = new OR();
  }

  virtual bool output() {
    component[2]->input[0] = this->input[0]; // NOT gate for input[0]
    component[3]->input[0] = this->input[1]; // NOT gate for input[1]

    component[0]->input[0] =
        component[2]; // AND gate: NOT input[0] and input[1]
    component[0]->input[1] = this->input[1];

    component[1]->input[0] =
        this->input[0]; // AND gate: input[0] and NOT input[1]
    component[1]->input[1] = component[3];

    component[4]->input[0] =
        component[0]; // OR gate combining the two AND gates
    component[4]->input[1] = component[1];

    return component[4]->output();
  }

private:
  Gate *component[5];
};

class Adder {
public:
  virtual void setValue(bool, int) = 0;
  virtual void setValue(Gate *, int) = 0;
  virtual Gate *sum() = 0;
  virtual Gate *carryOut() = 0;
};

class OneBitHalfAdder : public Adder {
public:
  OneBitHalfAdder() {
    component[0] = new AND();
    component[1] = new XOR();
  }

  virtual void setValue(bool val, int pin) {
    component[0]->setValue(val, pin);
    component[1]->setValue(val, pin);
  }

  virtual void setValue(Gate *gate, int pin) {
    component[0]->setValue(gate, pin);
    component[1]->setValue(gate, pin);
  }

  virtual Gate *sum() { return component[1]; }

  virtual Gate *carryOut() { return component[0]; }

private:
  Gate *component[2]; // component[0] is AND, component[1] is XOR
};

class OneBitFullAdder : public Adder {
public:
  OneBitFullAdder() {
    a[0] = new OneBitHalfAdder();//表示第一個半加器
    a[1] = new OneBitHalfAdder();//表示第二個半加器
    carry = new OR();
  }

  virtual void setValue(bool val, int pin) {
    if (pin < 2) {
      a[0]->setValue(val, pin);
    } else {
      a[1]->setValue(val, 0);
    }
  }

  virtual void setValue(Gate *gate, int pin) {
    if (pin < 2) {
      a[0]->setValue(gate, pin);
    } else {
      a[1]->setValue(gate, 0);
    }
  }

  virtual Gate *sum() {
    a[1]->setValue(a[0]->sum(), 1);//第一個半加器的sum進入到第二個半加器的第一個腳位
    return a[1]->sum();//回傳第二個半加器的sum。
  }

  virtual Gate *carryOut() {
    carry->setValue(a[0]->carryOut(), 0);//第一個半加器的carryout進到OR的第一個腳位。
    carry->setValue(a[1]->carryOut(), 1);//第二個半加器的carryout進到OR的第二個腳位。
    return carry;
  }

private:
  Adder *a[2]; // Two half adders
  Gate *carry; // OR gate for final carry out
};
