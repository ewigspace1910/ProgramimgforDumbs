function Dog(name, nation){
	this.name = name;
	this.country = nation;
}

Dog.prototype.wakeup = function (){
	console.log(this.name + " from " + this.country + " Wake Up!");
};

let Hachiko = new Dog("hihi","Japan");

Hachiko.wakeup();

function ShowDog(name, nation, clothes){
	
	this.clothes = clothes;
	Dog.call(this,name,nation);
	
	this.dance = ()=> console.log(this.name + " wear " + this.clothes + " is dancing!");
}
ShowDog.prototype = new Dog;

let Milu = new ShowDog("minu ", "VN", "ao choang cap 3");
Milu.wakeup();
Milu.dance();

// class

const Name = Symbol("name");
class Cat {
	constructor(name,type){
		
		this.name = name;
		this.type = type;
		
	}
	wakeup() {
		console.log(this.name + " type " + this.type + " Wake Up!");
		//console.log([Name]);
	
	}
	//let Name = Symbol();
	[Name](){
		console.log("symbol \n");
	}
}

let Mimi = new Cat("Dung","Lien ha");
Mimi.wakeup();
console.log(Mimi["name"]);
Mimi[Name]();
Mimi[Name] = ()=> {console.log("SSSS!");}
Mimi[Name]();

// map
let M = new Map();
// class + symbol
const x = Symbol("x");
const y = Symbol("y");
class Vec {
	
	constructor($x,$y){
		
		this[x] = $x;
		this[y] = $y;
		this._col = "red"; //_propertyName => private in ES6
		//this.#privatevalue = 110000; 
		//In ES2019, private class fields are defined using a hash # prefix
		//this.module = ($x**2 + $y**2)**(1/2);
		
	}
	
	//setter getter
	get colvector(){
		return this._col;
	}
	set colvector($value){
		this._col = $value;
	}
	
}
//let x = new Vec(2,1); => loi vi x la ki hieu roi
let ab = new Vec(3,4);

//inheritance 
class Group{
	constructor(){
		this.size = 0;
	}
	set(key){
		this[key] = this[key] || (this.size++ > 0) ? 1:1;
	}
	del(key){
		delete(this[key]);
		return (this.size>0) ? --this.size : 0;
	}
	has(key){
		return this[key] && true;
	}
	
}

class NumGroup extends Group {
	constructor(){
		super(); //  goi constructor cua SubClass
	}
	set(key){
		if(typeof(key) === "number") super.set(key);
		//da hinh
	}
} 
//Symbol.iterator

