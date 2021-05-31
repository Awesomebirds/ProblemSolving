{
  interface Graph {
    getNodeSize(): number;
    getAdjustMatrix(): Array<Array<boolean>>;
    addEdge(firstNode: number, secondNode: number): void;
  }

  class GraphI implements Graph {
    private _nodeSize: number = 0;
    private _adjustMatrix: Array<Array<boolean>> = [];
    private visited: Array<boolean> = []; //방문했는지 여부를 저장하는 배열

    //getter
    getNodeSize = () => this._nodeSize;
    getAdjustMatrix = () => this._adjustMatrix;

    //constructor
    constructor(nodeSize: number) {
      this._nodeSize = nodeSize;

      for (let i = 0; i < nodeSize; i++) {
        const tempArray = [];
        for (let j = 0; j < nodeSize; j++) {
          tempArray.push(false);
        }
        this._adjustMatrix.push(tempArray); //인접행렬 생성
      }

      for (let i = 0; i < this._nodeSize; i++) {
        this.visited.push(false); //false로 초기화
      }
    }

    //간선 추가
    addEdge = (firstNode: number, secondNode: number): void => {
      firstNode--;
      secondNode--;

      this._adjustMatrix[firstNode][secondNode] = this._adjustMatrix[
        secondNode
      ][firstNode] = true;
    };

    //깊이 우선 탐색
    bfs = (nodeNum: number): void => {
      if (this._nodeSize == 0) return; //노드가 없으면 중단

      console.log(nodeNum); //방문한 노드 출력
      nodeNum--; //노드 넘버와 인덱스를 맞추기 위해 1을 뺌
      this.visited[nodeNum] = true; //방문한 노드를 저장함

      for (let i = 0; i < this._nodeSize; i++) {
        if (this._adjustMatrix[nodeNum][i] && !this.visited[i]) {
          //간선이 있고, 방문하지 않은 노드일 때
          this.bfs(i + 1);
        }
      }
    };
  }

  const myGraph = new GraphI(10);

  myGraph.addEdge(1, 2);
  myGraph.addEdge(1, 3);
  myGraph.addEdge(2, 4);
  myGraph.addEdge(2, 5);
  myGraph.addEdge(4, 8);
  myGraph.addEdge(5, 8);
  myGraph.addEdge(3, 6);
  myGraph.addEdge(3, 7);
  myGraph.addEdge(6, 8);
  myGraph.addEdge(7, 8);

  console.log(myGraph.getAdjustMatrix());
  myGraph.bfs(1);
}
