//js project mail delivery robot
console.log("\n hihihi jspr1");
//cosnt data
const map = ["Office-A","Office-T","Office-H","T-K","T-Office",
	"K-T","K-H","K-L","K-N","N-K","N-J","J-N","J-D","J-L","L-J","L-K","L-H","L-C","C-L",
	"C-H","C-D","H-C","H-Office","H-K","H-L","D-C","D-J","D-A","A-D","A-C","A-Office"];
const parcels = [{address : "D"},{address : "J"},{address : "K"},{address : "L"},
	{address : "L"},{address : "T"}];


//office manager 
class MailOffice{
	//property
	constructor(){
		this.graphs = {};
		this.parcels = [];
	}
	//method
	makeGraph(map){
		let tmp = map.map(line =>line.split("-"));
		for(let pair of tmp ) {
			this.graphs[pair[0]] = this.graphs[pair[0]] || [];
			this.graphs[pair[0]].push(pair[1]);
		} 
		return this.graphs;
	}
	inputParcels(parcels){
		//tam thoi chua co gi
		this.parcels = parcels;
	}
	
	distributeParcel(Robot){
		Robot.parcels = this.parcels;
	}
}

//robot
class MailRobot{
	//property
	constructor(graphs){
		this.maps = graphs;
		this.parcels = [];
		this.place = "Office"; // current place
		this.distination = [];
	}
	//method	
	//tim dich den
	findDistination(){
		// tra ve mang lo trinh dia chi di qua
		let check = false;
		let tmpRoad =  this.maps[this.place],checkRoad = [];
		this.distination = [];
		while (check === false){
	
			
		}
	}
	//giao hang
	goShip(){
		//thuat toan tim duowng
		let petroliem = 100;
		while (petroliem > 0 && this.parcels.length > 0){
			this.distination = findDistination();
			//di den dia diem
			this.distination.forEach(x => console.log("\n di toi" + x));
			console.log(" Giao hang! \n");
			
			petroliem -= this.distination.length;
		}
		
		console.log("het " + 100-petroliem + " lit xang va con " +this.parcels.length+ " don hang");
	}
}

//process
let Foffice = new MailOffice();
let Airobot = new MailRobot(Foffice.makeGraph(map));
// giao hang cho robot
Foffice.distributeParcel(Airobot);
// ro bot di giao
Airobot.goShip();