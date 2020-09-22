//test let and var
// let  bloclscope
// var global
for(let a = 1;a<3;a++){
	//setTimeout(()=>console.log(a),1000);
	console.log(" \na=" + a);
}
console.log("===========================\n");
for(var a = 1;a<3;a++){
	//setTimeout(()=>console.log(a),2000);
	console.log(" \na=" + a);
}
//
console.log("==============");
const weekDay = function(){
	
	
	const names = ["cn","t2","t3","t4","t5","t6","t7"];
	return {
		nameDay(number_) {return names[number_];},
		numberDay(name_){return names.indexOf(name_);}
	};
}(); // doi tuong dc khoi tao chu ko phai ham
console.log(weekDay.nameDay(3-1));
console.log(weekDay.numberDay("t3"));
console.log(weekDay.nameDay(weekDay.numberDay("t2")));
console.log(weekDay);
console.log(typeof(weekDay));
// -> 1 dang module, code,everionment dc bao trong hamf, return/exxpert la 1 obj chua method
// goi laf interfaces

let car = {
	meme : 20,
	getMeme : function(){
		console.log(this.meme + "\n");
	}
}
car.getMeme();

let car1 = {
	meme : 20,
	getMeme : ()=>{
		console.log(this.meme + "\n");
	}
}
car1.getMeme();