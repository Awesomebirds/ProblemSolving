#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

class Point2D {
  public:
    int x;
    int y;
    int index;

    Point2D(int index, int x, int y){
      this->index = index;
      this->x = x;
      this->y = y;
    }

    Point2D(int x, int y) {
      this->index = 1;
      this->x = x;
      this->y = y;
    }

    long long getSquaredDistanceTo(Point2D target) {
      //두 좌표간의 제곱거리를 계산
      long long dx= abs(this->x - target.x);
      long long dy= abs(this->y - target.y);
      return dx * dx + dy * dy;
    }

    double getDistanceTo(Point2D target) {
      //두 좌표간의 실수 거리를 계산
      long long sqd = this->getSquaredDistanceTo(target);
      return sqrt(sqd);
    }

    bool operator < (const Point2D& other) const {
      //각 좌표의 우선순위를 비교하기 위한 비교 연산자

      //x좌표가 다르다면 x좌표를 기준으로 비교한다.
      if (this->x != other.x) {
        return this->x < other.x;
      }

      //x좌표가 같다면 y좌표를 기준으로 비교한다.
      return this->y < other.y;
    }
};

long long getMaximumSquareArea(int n, const vector<Point2D>& points){
  long long answer = 0;

  //모든 점을 Set에 저장한다.
  set<Point2D> pSet;
  for(int i = 0; i < n; i++){
    pSet.insert(points[i]);
  }

  for(int i = 0; i < n; i++){
    Point2D pa = points[i];
    for (int j = 0; j < n; j++){
      Point2D pb = points[j];
      //두 기준점 pa와 pb를 지정한다.
      //선분 pa-pb가 정사각형의 한 변이라고 하자.

      // TODO

    }
  }

  return answer;
}

void process() {
  int n; //좌표의 수
  cin >> n; //입력받음

  vector<Point2D> points;

  for (int i = 0; i < n; i++){
    int x, y;
    cin >> x >> y;
    points.push_back(Point2D(i, x, y));
  }

  long long answer = getMaximumSquareArea(n, points);

  cout << fixed << setprecision(2) << answer << endl;
}

int main() {
  int caseSize; //케이스 사이즈
  cin >> caseSize; //입력받음

  for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++){
    //케이스 사이즈만큼 반복
    process();
  }

  return 0;
}