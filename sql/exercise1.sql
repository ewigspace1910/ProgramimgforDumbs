create database if not exists my_database;
use my_database;
create table if not exists orders(
	/* thuoc tinh */
    orderNumber INT(11) not null auto_increment,
    orderDate datetime not null,
    requiredDate datetime not null,
    shippedDate datetime not null,
    statusOrder varchar(15),
    comments text,
    customerNumber int(11) not null,
    
    /*constraint*/
    constraint id_order_primarykey primary key (orderNumber)
);

create table if not exists productlines (
	productLine varchar(15) not null unique,
    textDescription varchar(499),
    htmlDescription mediumtext,
    image mediumblob,
    
    /*constraint*/
    constraint producline_primarykey primary key ( productLine)
);

create table if not exists products (
	productCode varchar(15) not null unique,
    productName varchar(40) not null,
    productLine varchar(15) not null unique,
    productScale varchar(50) not null,
    productVendor varchar(50) not null,
    productDescription text,
	quantityInStock smallint(6),
    buyPrice double,
	/*constrain*/
    constraint productCode_primerykey primary key (productCode),
    constraint productLine_poreignKey foreign key (productLine)
		references productlines (productLine) ON DELETE RESTRICT ON UPDATE CASCADE
);

create table if not exists orderdetails (
	orderNumber int(11) not null auto_increment,
    productCode varchar(15) not null unique,
    quantityOrdered int(11) not null,
    priceEach double not null,
    orderLineNumber smallint(6),
    
    /* constrain*/
    primary key (orderNumber, productCode),
    constraint orderNumber_fk foreign key (orderNumber)
		references orders(orderNumber) on delete restrict on update cascade,
	constraint productCode_fk foreign key (productCode)
		references products(productCode) on delete restrict on update cascade
);