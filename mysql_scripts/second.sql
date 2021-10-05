delimiter //
create procedure `spFilterProductsByNRP` (in priceLevel float)

begin
    select ProductName, WholesalePrice, NetRetailPrice,
    case
        when NetRetailPrice <= 24.99 then 'Cheap'
        when NetRetailPrice > 24.99 and NetRetailPrice <= 79.99 then 'Mid-price'
        when NetRetailPrice > 79.99 and NetRetailPrice <= 2499.99 then 'Expensive'
        else 'Very Expensive'
    end as 'Price Point',
    UnitKGWeight
    from Products
    where NetRetailPrice <= priceLevel
    order by ProductName;
end //

delimiter ;
