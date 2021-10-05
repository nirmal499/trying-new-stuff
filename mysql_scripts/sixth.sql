delimiter $$

create trigger tr_Products_OnInsert after insert on Products
for each row
begin
    /*
		To test:	INSERT INTO 	Products(ProductCategoryID, SupplierID,
						ProductName, ProductImage, NetRetailPrice,
						AvailableQuantity, WholesalePrice,
						UnitKGWeight, Notes)

				VALUES(3, 3, 'peanut butter', NULL, 3.79, 1000, 2.69,
						0.75, 'caution: high calorie');

				SELECT	P.*
				FROM	Products P
				WHERE	P.SupplierID = 3;
	*/

    declare supplierID int;
    declare supplierProductCount int;
    declare supplierCountText varchar(1000);

    set supplierID = (
        select new.SupplierID
    );

    set supplierProductCount = (
        select count(P.ProductID) from Products P inner join Suppliers S on
        P.SupplierID = S.SupplierID where P.SupplierID = supplierID
    );

    set supplierCountText = (
        select concat("This supplier (Supplier ",cast(supplierID as char),")")
    );

    set supplierCountText = (
        select concat(supplierCountText, " has ", cast(supplierProductCount AS CHAR))
    );

    set supplierCountText = (
        select concat(supplierCountText," products available here as of ")
    );

    set supplierCountText = (
        select concat(supplierCountText,date_format(now(),"%b %d,%Y"))
    );

    update Suppliers
    set Suppliers.Notes = supplierCountText
    where Suppliers.SupplierID = supplierID;

end$$

delimiter ;