delimiter $$

create trigger tr_OrderItems_OnInsert after insert on OrderItems
for each row
begin
        /*
			To test:	INSERT INTO	OrderItems(OrderID, ProductID, Quantity,
							UnitPrice, Discount, Notes)
					VALUES(1, 6, 12, 4.49, 0.00, NULL);
					SELECT	C.BalanceNotes
					FROM	Customers C
					WHERE	C.CustomerID = 2;
		*/
		declare balanceNotesText varchar(1000);
		declare customerID int;
		declare orderBalance decimal(10,2);
		declare orderIDVal int;
		declare paymentBalance decimal(10,2);
		declare runningTotal varchar(50);

        set orderIDVal = (
            select new.OrderID
        );

        set customerID = (
            select O.CustomerID from Orders O where O.OrderID = orderIDVal
        );

        /* Calculate the order balance for the customer*/
        set orderBalance = (
            select sum(OI.Quantity * (OI.UnitPrice - OI.Discount))
            from OrderItems OI inner join Orders O on
            OI.OrderID = O.OrderID where
            O.CustomerID = customerID
        );

        /*Calculate the payment balance for the customer*/
        set paymentBalance = (
            select sum(P.Amount) from Payments P inner join Orders O on
            P.OrderID = O.OrderID where O.CustomerID = customerID
        );

        set runningTotal = (
            select cast((orderBalance - paymentBalance) as char)
        );

        set balanceNotesText = (
            select concat("Customer ",cast(customerID as char))
        );

        set balanceNotesText = (
            select concat(balanceNotesText," has a new running balance of $")
        );

        set balanceNotesText = (
            select concat(balanceNotesText,runningTotal," as of ")
        );

        set balanceNotesText = (
            select concat(balanceNotesText,date_format(now(),"%b %d, %Y"))
        );

        update Customers
        set Customers.BalanceNotes = balanceNotesText
        where Customers.CustomerID = customerID;

end$$

delimiter ;
