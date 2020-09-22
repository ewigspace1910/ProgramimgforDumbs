console.log("\n-----------js exception-------------\n");  
//exception
function promptDirection(question){
    let result = prompt(question);
	 // throw new Error("Invalid direction: " + result); tao loi o day => du dung nhung van bao loi
    if (result.toLowerCase() == "left") return "L";
    if (result.toLowerCase() == "right") return "R";
    throw new Error("Invalid direction: " + result); // neu khong trung 2 if-> tao 1 loi = throw 
}

function look() {
    if (promptDirection("Which way?") == "L") {
        return "a house";
    } else {
        return "two angry bears";
    }
}

try {
    console.log("You see", look());
} catch(error){
    console.log("Something went wrong: " + error);
    console.log("mess :" + error.message);
	//cactch phat hien loi -> gui tin nhan
}

//exception2
const accounts = { a: 100,b:100,c:0};

function transfer(from, amount) {
    if (accounts[from] < amount) return ;        
    let progress = 0;
    try {
      accounts[from] -= amount;
      progress = 1;
      accounts[getAccount()] += amount;
      progress = 2; 
    }finally {
        if (progress == 1) { 
			accounts[from] += amount; 
			console.log("loi 101");
		}
    }
}

//exception 3
for (;;) {
   try {
       let dir = promtDirection("Where?"); // ← typo!
        console.log("You chose ", dir);
        break;
    } catch(e) {
	  console.log("mess :" + e.message);
	}
}
//end