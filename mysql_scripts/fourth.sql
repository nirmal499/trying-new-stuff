delimiter //
create function `fnTotalSalesRvnByCast` (CustomerID Integer)
returns float
deterministic
begin
    declare returnValue float;

    set returnValue = (
        select sum(OI.Quantity * (OI.UnitPrice - OI.Discount))
        from OrderItems OI inner join Orders O on OI.OrderID = O.OrderID
        where O.CustomerID = CustomerID
    );

    if (returnValue is null) then /* If a customer has not placed an order,(s)he has total revenue value of null.*/
        set returnValue = 0.00;
    end if;

    return (returnValue);

end //

delimiter ;
