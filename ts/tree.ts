{
  type Node<T> = null | {
    body: T;
    left: Node<T> | null;
    right: Node<T> | null;
  };

  interface Tree<T> {
    preorderReadTree(): void;
  }

  class TreeI<T> implements Tree<T> {
    private node: Node<T> = null;

    // constructor(body: T) {
    //   this.node = {
    //     body,
    //     left: null,
    //     right: null,
    //   };
    // }

    preorderReadTree = (node?: Node<T>) => {
      const currentNode = node || this.node;

      console.log(currentNode.body); //D

      currentNode.left && this.preorderReadTree(currentNode.left); //L
      currentNode.right && this.preorderReadTree(currentNode.right); //R
    };

    inorderReadTree = (node?: Node<T>) => {
      const currentNode = node || this.node;

      currentNode.left && this.inorderReadTree(currentNode.left); //L

      console.log(currentNode.body); //D

      currentNode.right && this.inorderReadTree(currentNode.right); //R
    };

    postorderReadTree = (node?: Node<T>) => {
      const currentNode = node || this.node;

      currentNode.left && this.postorderReadTree(currentNode.left); //L
      currentNode.right && this.postorderReadTree(currentNode.right); //R
      console.log(currentNode.body); //D
    };

    addNode = (body: string) => {};

    editTree = (node: Node<T>): void => {
      this.node = node;
    };
  }

  const myTree = new TreeI<string>();
  const myNode: Node<string> = {
    body: "a",
    left: {
      body: "b",
      left: {
        body: "d",
        left: {
          body: "h",
          left: null,
          right: null,
        },
        right: null,
      },
      right: {
        body: "e",
        left: {
          body: "i",
          left: null,
          right: null,
        },
        right: {
          body: "j",
          left: null,
          right: null,
        },
      },
    },
    right: {
      body: "c",
      left: {
        body: "f",
        left: null,
        right: null,
      },
      right: {
        body: "g",
        left: null,
        right: {
          body: "k",
          left: null,
          right: null,
        },
      },
    },
  };

  myTree.editTree(myNode);
  myTree.postorderReadTree();
}
