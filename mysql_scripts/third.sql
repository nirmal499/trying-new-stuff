delimiter $$
create procedure `spFilterOrdersByItemQuantity` (in orderItemQuantityValue int)
begin
    select O.OrderID,sum(OI.Quantity) as 'Total Order Item Quantity'
    from Orders O inner join OrderItems OI on O.OrderID = OI.OrderID
    group by O.OrderID having sum(OI.Quantity) <= orderItemQuantityValue
    order by O.OrderID;
end$$

delimiter ;
