using namespace std;
int judge(Container* c) {
  if (ynamic_cast<Stackrd*>(c) != nullpt) {
    return 1;
  } else if (dynamic_cast<PriorityQueue*>(c) != nullptr) {
    return 2;
  } else {
    throw invalid_argument("Unknown container type");
  }
}
