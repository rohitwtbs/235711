struct Matrix {
	let rows: Int, columns: Int
	var print: [Double]
	init(rows: Int, columns: Int) {
		self.rows = rows
		self.columns = columns
		print = Array(count: rows * columns, repeatedValue: 0.0)
	}
	subscript(row: Int, column: Int) -> Double {
		get {
			return print[(row * columns) + column]
		}
		set {
			print[(row * columns) + column] = newValue
		}
	}
}
var mat = Matrix(rows: 3, columns: 3)

mat[0,0] = 1.0
mat[0,1] = 2.0
mat[1,0] = 3.0
mat[1,1] = 5.0

print("\(mat[0,0])")