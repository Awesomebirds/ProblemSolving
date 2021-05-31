{
  type Node<T> = {
    body: T;
    next: Node<T> | null;
  };

  class Queue<T> {
    private _size = 0;
    size = () => this._size;

    empty = () => {
      if (this._size === 0) {
        return true;
      }
      return false;
    };

    private frontNode: Node<T> = null;
    front = () => this.frontNode.body;

    private backNode: Node<T> = null;
    back = () => this.backNode.body;

    push = (data: T) => {
      const node: Node<T> = {
        body: data,
        next: null,
      };
      if (this.empty()) {
        this.frontNode = node;
      } else {
        this.backNode.next = node;
      }
      this.backNode = node;
      this._size++;
    };

    pop = () => {
      if (this.empty()) {
        throw new Error("The queue is empty");
      }
      const next = this.frontNode.next;
      this.frontNode = next;
      this._size--;
    };
  }
}
