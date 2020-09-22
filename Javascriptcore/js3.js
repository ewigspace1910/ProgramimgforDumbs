//regular expression

//
console.log(/'\d+'/.test("'123'")); // more degis
console.log(/'\d+'/.test(" '' "));
console.log(/'\d+'/.test("'123ssss'"));
console.log(/'\d+'/.test("'123''ssss'"));
console.log("\n");




console.log(/[\d.]/.test("123"));
console.log(/[\d.]/.test("."));
console.log(/[^01]/.test(" ")); // ngoai tru 0 1 -> true
console.log("--------------------");
console.log(/\d\d\d \d\d\d \d\d\d\d/.test("0982482398"));
console.log(/\d\d\d \d\d\d \d\d\d\d/.test("098 248 2398"));
console.log("-------------")
console.log(/\d{2,3} \d{3} \d{4}/.test("098 248 2398"));
console.log(/\d{2,3} \d{3} \d{,4}/.test("03 248 23985")); // toi da 4 so cuoi
console.log(/\d{2,3} \d{3} \d{4}/.test("03 248 23598")); // toi thieu 4 so cuoi
console.log(/\d{2,3} \d{3} \d{4}/.test("0 248 2398"));

console.log("--------------------");
let quoteText = /'[^']*'/;
console.log(quoteText.exec("helo is 'halo'! "));

quoteText = /'([^']*)'/;
console.log(quoteText.exec("helo is 'halo'! "));

console.log(/bad(ly)?/.exec("bad")); //vi phan tu thu 2 trong ngoac Gruop khong tim thay => undefined 
console.log(/bad(ly)?/.exec("badly"));
console.log(/bad(ly)?/.exec("badli"));

console.log(/(\d)+/.exec("123"));
console.log(/(\d)*/.exec("123")); // match nhieu lan -> phan tu cuoi se thay the ket thuc


console.log("bakabaka".replace(/[ak]/,"i"));
console.log("bakabaka".replace(/[ak]/g,"i"));
console.log("bakabaka".match(/[ak]/));
console.log("bakabaka".match(/[ak]/g));

var string = "A, Nguyen\n B, Tran \n C, Pham";
console.log(string);
console.log(string.replace(/\b\w+, \w+\b/,"ho ten "));
console.log(string.replace(/\b\w+, \w+\b/g,"ho ten "));
console.log(string.replace(/\b(\w+), (\w+)\b/g,"$2 $1 "));
console.log(string.replace(/\b(\w+), (\w+)\b/g, str => str.toUpperCase()));

string = "1 con chim, 2 con chim";
function birts(match,group1,group2){
	return "kq = " + match + (group1 -1) + group2.toUpperCase();
}

console.log(string.replace(/(\d+) (\w+ \w+)/g,birts));

function birts1(match,group2,group1){
	return "kq = " + match + (group1 -1) + group2.toUpperCase();
}

console.log(string.replace(/(\d+) (\w+ \w+)/g,birts1));

console.log("------------greedy---------------");
console.log("ferret, ferry and ferrari".match(/ferr\w+/g));
