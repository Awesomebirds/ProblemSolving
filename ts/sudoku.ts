interface Sudoku {
  readonly MAX_ROW: number;
  readonly MAX_COLUMN: number;
  readonly table: Array<number>;
  getRowNumber(index: number): number;
  getColumNumber(index: number): number;
  getGroupNumber(row: number, column: number): number;
}

class SudokuImpl implements Sudoku {
  readonly MAX_ROW = 9;
  readonly MAX_COLUMN = 9;

  private _table = [];
  public get table() {
    return this._table;
  }

  private initTable() {
    for (let i = 0; i <= this.MAX_COLUMN * this.MAX_ROW; i++) {
      this._table.push(i);
    }
  }

  constructor() {
    this.initTable();
  }

  getRowNumber(index: number): number {
    //행을 구하는 함수
    return Math.floor((index - 1) / this.MAX_ROW) + 1;
  }

  getColumNumber(index: number): number {
    //열을 구하는 함수
    return ((index - 1) % 9) + 1;
  }

  getGroupNumber(row: number, column: number): number {
    //그룹 인덱스를 구하는 함수
    return Math.floor((row - 1) / 3) * 3 + 1 + Math.floor((column - 1) / 3);
  }

  solve(index: number): Array<number> {
    const row = this.getRowNumber(index);
    const column = this.getColumNumber(index);
    const group = this.getGroupNumber(row, column);
    return [row, column, group];
  }
}

const mySudoku = new SudokuImpl();
console.log(mySudoku.solve(58));
