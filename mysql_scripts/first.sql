set @var1 = null;
select @var1;           -- Output the value of @var1

set @var1 = 3;
select @var1;

set @var1 = @var1 - 7;
select @var1;

set @var1 = @var1 + 5;
select @var1;
