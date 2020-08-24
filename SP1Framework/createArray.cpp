
char** createArray(int column, int row) {

	char** array = new char* [row];
	for (int i = 0; i < row; ++i)
		array[i] = new char[column];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			array[i][j] = ' ';
		}
	}
	return array;
}