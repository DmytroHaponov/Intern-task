Program implements:

1) opening qsqlite data bases and viewing data;
2) creating DBs with 1 default table which has 3 columns: id (primary, not editable), name and age. 
3) adding, editing and deleting data to such DBs. By double clicking any cell in table the corresponding lineEdit field
is filled with the data from selected row. Name and age fields can be edited or the whole row can be deleted.
  In case non-existent ID is typed and Edit or Delete is clicked - the error is shown.
  Drawback - in case different rows (which means they have different ID values) have the same Name and\or Age, double 
  clicking any of them will select the last row into the lineEdit fields for editing.
