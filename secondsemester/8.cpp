struct p {
    double x;
    double y;
};

class Path {
public:
    Path(Segment* arr, int n) {
        p a[500];
        int m = 0;
        double sum = 0;
        bool cycle = 1;
        for (int i = 0; i < n; i++) {
            sum += arr[i].length();
            for (int j = 0; j < i; j++)
                if ((arr[i].getEnd(1).getX() == a[j].x && arr[i].getEnd(1).getY() == a[j].y) || (arr[i].getEnd(0).getX() != arr[i - 1].getEnd(1).getX() && arr[i].getEnd(0).getY() != arr[i - 1].getEnd(1).getY() && i > 0)) {
                    cycle = 0;
                    break;
                }
            a[i].x = arr[i].getEnd(0).getX();
            a[i].y = arr[i].getEnd(0).getY();
        }
        if (cycle) cout << sum << endl;
        else cout << "-1\n";
    }
};