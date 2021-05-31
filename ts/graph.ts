{
  interface Graph {
    getNodeSize(): number;
    getAdjustMatrix(): Array<Array<boolean>>;
    addEdge(firstNode: number, secondNode: number): void;
  }

  class GraphI implements Graph {
    private _nodeSize: number = 0;
    private _adjustMatrix: Array<Array<boolean>> = [];

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
    bfs = (): void => {
      if (this._nodeSize == 0) return; //노드가 없으면 중단

      const visited = []; //방문했는지 여부를 저장하는 배열
      for (let i = 0; i < this._nodeSize; i++) {
        visited.push(false); //false로 초기화
      }
    };
  }

  const myGraph = new GraphI(4);

  myGraph.addEdge(1, 2);
  myGraph.addEdge(1, 3);
  myGraph.addEdge(1, 4);
  myGraph.addEdge(2, 3);
  myGraph.addEdge(3, 4);

  console.log(myGraph.getAdjustMatrix());
}
