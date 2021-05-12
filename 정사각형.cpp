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
  set<Point2D> pSet; //디폴트가 오름차순이므로 클래스에 대소관계를 계산할 오퍼레이터를 추가해야함
  for(int i = 0; i < n; i++){
    pSet.insert(points[i]); //세트 자료구조에 모든 값을 넣어준다.
  }

  //임의의 a와 b 두 점을 잡는다.
  for(int i = 0; i < n; i++){
    Point2D pa = points[i]; //점 a
    for (int j = 0; j < n; j++){
      Point2D pb = points[j]; //점 b
      if(i == j) continue; //같은 점이면 넘어감

      //두 기준점 pa와 pb를 지정한다.
      //선분 pa-pb가 정사각형의 한 변이라고 하자.

      // 두 점의 거리(선분의 길이)의 제곱은 정사각형의 넓이가 된다.
      long long area = pa.getSquaredDistanceTo(pb);

      //이미 구한 사각형보다 넓이가 작다면 건너뛴다.
      if (area < answer) continue;

      //pa -> pb 방향의 x, y 좌표에 대한 거리를 구한다.
      int dx = pb.x - pa.x;
      int dy = pb.y - pa.y;

      //벡터 <dx, dy>를 0-도로 회전시키면 <-dy, dx>가 된다.
      //pa와 pb에 벡터 <-dy, dx>를 각각 더해 정사각형을 구성하는 두 점
      //pd, pc를 계산할 수 있다.
      Point2D pd(pa.x - dy, pa.y + dx);
      Point2D pc(pb.x - dy, pb.y + dx);

      //pd, pc와 결정적이므로 이 점이 pSet에 존재하는 점인지 검사한다.
      if (pSet.count(pc) > 0 && pSet.count(pd) > 0) { //존재 == 0, 존재x == 1
        answer = max(answer, area);
      }
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