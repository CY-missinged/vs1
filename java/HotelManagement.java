// import java.util.ArrayList;
// import java.util.List;

// class HotelManagement {

//     private static HotelManagement instance = new HotelManagement();

//     private List<ParkingLot> parkingLots;
//     private List<Room> rooms;
//     private List<DiningTable> diningTables;
//     private List<Housekeeper> housekeepers;
//     private List<Receptionist> receptionists;
//     private List<LobbyAttendant> lobbyAttendants;

//     public HotelManagement() {
//         rooms = new ArrayList<>();
//     }

//     public HotelManagement(int parkingLotCount, int roomCount, int diningTableCount,
//             int housekeeperCount, int receptionistCount, int lobbyAttendantCount) {
//         // 初始化停车场、客房、餐桌、客房服务人员、前台服务员和大厅服务员数量
//         this.parkingLots = new ArrayList<>();
//         for (int i = 1; i <= parkingLotCount; i++) {
//             ParkingLot parkingLot = new ParkingLot(i);
//             this.parkingLots.add(parkingLot);
//         }
//         this.rooms = new ArrayList<>();
//         for (int i = 1; i <= roomCount; i++) {
//             Room room = new Room(i);
//             this.rooms.add(room);
//         }
//         this.diningTables = new ArrayList<>();
//         for (int i = 1; i <= diningTableCount; i++) {
//             DiningTable diningTable = new DiningTable(i);
//             this.diningTables.add(diningTable);
//         }
//         this.housekeepers = new ArrayList<>();
//         for (int i = 1; i <= housekeeperCount; i++) {
//             Housekeeper housekeeper = new Housekeeper(i);
//             this.housekeepers.add(housekeeper);
//         }
//         this.receptionists = new ArrayList<>();
//         for (int i = 1; i <= receptionistCount; i++) {
//             Receptionist receptionist = new Receptionist(i);
//             this.receptionists.add(receptionist);
//         }
//         this.lobbyAttendants = new ArrayList<>();
//         for (int i = 1; i <= lobbyAttendantCount; i++) {
//             LobbyAttendant lobbyAttendant = new LobbyAttendant(i);
//             this.lobbyAttendants.add(lobbyAttendant);
//         }
//     }

//     // 停车功能
//     public synchronized ParkingLot parkCar(Car car) {
//         for (ParkingLot parkingLot : this.parkingLots) {
//             if (parkingLot.isAvailable()) {
//                 parkingLot.park(car);
//                 return parkingLot;
//             }
//         }
//         return null;
//     }

//     // 客房预约和退房功能
//     public synchronized void checkIn(Customer customer, int roomNumber) {
//         Room room = this.rooms.get(roomNumber - 1);
//         if (room.isAvailable()) {
//             room.checkIn(customer);
//         }
//     }

//     public synchronized void checkOut(int roomNumber) {
//         Room room = this.rooms.get(roomNumber - 1);
//         if (!room.isAvailable()) {
//             room.checkOut();
//         }
//     }

//     // 餐桌预约和取消预约功能
//     public synchronized void bookDiningTable(Customer customer) {
//         for (DiningTable diningTable : this.diningTables) {
//             if (diningTable.isAvailable()) {
//                 diningTable.book(customer);
//                 return;
//             }
//         }
//     }

//     public synchronized void cancelDiningTableBooking(int tableNumber) {
//         DiningTable diningTable = this.diningTables.get(tableNumber - 1);
//         if (!diningTable.isAvailable()) {
//             diningTable.cancel();
//         }
//     }

//     // 客房服务人员提供的服务
//     public synchronized void cleanRoom(int roomNumber) {
//         for (Housekeeper housekeeper : this.housekeepers) {
//             if (housekeeper.isAvailable()) {
//                 housekeeper.clean(roomNumber);
//                 return;
//             }
//         }
//     }

//     // 前台服务员提供的服务
//     public synchronized void bookRoom(Customer customer, int roomType) {
//         for (Receptionist receptionist : this.receptionists) {
//             if (receptionist.isAvailable()) {
//                 receptionist.book(customer, roomType);
//                 return;
//             }
//         }
//     }

//     // 大厅服务员提供的服务
//     public synchronized void helpCustomer(Customer customer) {
//         for (LobbyAttendant lobbyAttendant : this.lobbyAttendants) {
//             if (lobbyAttendant.isAvailable()) {
//                 lobbyAttendant.help(customer);
//                 return;
//             }
//         }
//     }

//     public static void main(String[] args) {
//         // 测试程序
//         HotelManagement hotel = new HotelManagement(3, 5, 10, 2, 3, 4);

//         // 启动停车场线程
//         for (ParkingLot parkingLot : hotel.parkingLots) {
//             new Thread(parkingLot).start();
//         }

//         // 启动客房线程
//         for (Room room : hotel.rooms) {
//             new Thread(room).start();
//         }

//         // 启动餐厅线程
//         for (DiningTable diningTable : hotel.diningTables) {
//             new Thread(diningTable).start();
//         }

//         // 启动客房服务人员线程
//         for (Housekeeper housekeeper : hotel.housekeepers) {
//             new Thread(housekeeper).start();
//         }

//         // 启动前台服务员线程
//         for (Receptionist receptionist : hotel.receptionists) {
//             new Thread(receptionist).start();
//         }

//         // 启动大厅服务员线程
//         for (LobbyAttendant lobbyAttendant : hotel.lobbyAttendants) {
//             new Thread(lobbyAttendant).start();
//         }

//         // 创建顾客并测试功能
//         Car car1 = new Car("A", "陕A-AB123");
//         Car car2 = new Car("B", "陕D-CD456");
//         Customer customer1 = new Customer("Tom", car1);
//         Customer customer2 = new Customer("Jack", car2);

//         // 顾客预约停车场
//         ParkingLot parkingLot1 = hotel.parkCar(car1);
//         ParkingLot parkingLot2 = hotel.parkCar(car2);

//         // 顾客预约住房和退房
//         hotel.checkIn(customer1, 2);
//         hotel.checkOut(2);
//         hotel.checkIn(customer2, 1);

//         // 顾客预约餐桌和取消预约
//         hotel.bookDiningTable(customer1);
//         hotel.cancelDiningTableBooking(1);

//         // 客房服务人员提供清洁服务
//         hotel.cleanRoom(3);

//         // 前台服务员提供预定服务
//         hotel.bookRoom(customer2, 2);

//         // 大厅服务员提供帮助服务
//         hotel.helpCustomer(customer1);
//     }

//     public static synchronized HotelManagement getInstance() {
//         if (instance == null) {
//             instance = new HotelManagement();
//         }
//         return instance;
//     }

//     public List<Room> getRooms() {
//         return rooms;
//     }

// }

// class ParkingLot implements Runnable {

//     // 编号

//     private int number;

//     private boolean available;
//     // 是否空闲

//     private Car car;
//     // 当前停在停车场的车辆

//     public ParkingLot(int number) {
//         this.number = number;
//         this.available = true;
//     }

//     public boolean isAvailable() {
//         return available;
//     }

//     public synchronized void park(Car car) {
//         // 停车
//         while (!this.available) {
//             try {
//                 wait();
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//         }
//         this.car = car;
//         this.available = false;
//         System.out.println(car + "在停车场" + this.number);
//         notifyAll();
//     }

//     public synchronized void take() {
//         // 取车
//         while (this.available) {
//             try {
//                 wait();
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//         }
//         this.car = null;
//         this.available = true;
//         System.out.println(car + "离开停车场" + this.number);
//         notifyAll();
//     }

//     @Override
//     public void run() {
//         // 停车场线程
//         while (true) {
//             try {
//                 Thread.sleep(500);
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//             if (!this.available) {
//                 this.take();
//             }
//         }
//     }
// }

// class Room implements Runnable {
//     private int number;
//     private boolean available;
//     private Customer customer;
//     private int type;

//     public Room(int number){
//         this.number = number;
//         this.available =true;
//     }

//     public Room(int number, int type) {
//         this.number = number;
//         this.available = true;
//         this.type = type;
//     }

//     public boolean isAvailable() {
//         return available;
//     }

//     public int getNumber() {
//         return number;
//     }

//     public int getType() {
//         return type;
//     }

//     public synchronized void checkIn(Customer customer) {
//         // 预约住房
//         while (!this.available) {
//             try {
//                 wait();
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//         }
//         this.customer = customer;
//         this.available = false;
//         System.out.println(customer.getName() + "选择住房" + this.number);
//         notifyAll();
//     }

//     public synchronized void checkOut() {
//         // 退房
//         while (this.available) {
//             try {
//                 wait();
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//         }
//         this.customer = null;
//         this.available = true;
//         System.out.println(customer.getName() + "退房" + this.number);
//         notifyAll();
//     }

//     @Override
//     public void run() {
//         // 客房线程
//         while (true) {
//             try {
//                 Thread.sleep(500);
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//             if (!this.available) {
//                 this.checkOut();
//             }
//         }
//     }
// }

// class DiningTable implements Runnable {
//     private int number;
//     private boolean available;
//     private Customer customer;

//     public DiningTable(int number) {
//         this.number = number;
//         this.available = true;
//     }

//     public boolean isAvailable() {
//         return available;
//     }

//     public synchronized void book(Customer customer) {
//         // 预约用餐
//         while (!this.available) {
//             try {
//                 wait();
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//         }
//         this.customer = customer;
//         this.available = false;
//         System.out.println(customer.getName() + "订餐在" + this.number);
//         notifyAll();
//     }

//     public synchronized void cancel() {
//         // 取消预约
//         while (this.available) {
//             try {
//                 wait();
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//         }
//         this.customer = null;
//         this.available = true;
//         System.out.println(customer.getName() + "取消了订餐" + this.number);
//         notifyAll();
//     }

//     @Override
//     public void run() {
//         // 餐厅线程
//         while (true) {
//             try {
//                 Thread.sleep(500);
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//             if (!this.available) {
//                 this.cancel();
//             }
//         }
//     }
// }

// class Customer {

//     private String name;
//     // 顾客姓名

//     private Car car;
//     // 顾客汽车

//     public Customer(String name, Car car) {
//         this.name = name;
//         this.car = car;
//     }

//     public String getName() {
//         return name;
//     }

//     public Car getCar() {
//         return car;
//     }

//     @Override
//     public String toString() {
//         return "顾客{" +
//                 "姓名='" + name + '\'' +
//                 '}';
//     }
// }

// class Car {
//     private String brand;
//     // 品牌

//     private String plateNumber;
//     // 车牌号

//     public Car(String brand, String plateNumber) {
//         this.brand = brand;
//         this.plateNumber = plateNumber;
//     }

//     public String getBrand() {
//         return brand;
//     }

//     public String getPlateNumber() {
//         return plateNumber;
//     }

//     @Override
//     public String toString() {
//         return "汽车品牌为'" + brand + '\'' +
//                 ", 车牌号为'" + plateNumber;
//     }
// }

// class Housekeeper implements Runnable {
//     private int number;
//     private boolean available;

//     public Housekeeper(int number) {
//         this.number = number;
//         this.available = true;
//     }

//     public boolean isAvailable() {
//         return available;
//     }

//     public synchronized void clean(int roomNumber) {
//         // 清洁客房
//         while (!this.available) {
//             try {
//                 wait();
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//         }
//         Room room = HotelManagement.getInstance().getRooms().get(roomNumber - 1);
//         System.out.println("客房服务人员" + this.number + "正在清洁" + room.getNumber() + "号房间");
//         try {
//             Thread.sleep(2000);
//         } catch (InterruptedException e) {
//             e.printStackTrace();
//         }
//         System.out.println("客房服务人员" + this.number + "清洁完毕");
//         this.available = false;
//         notifyAll();
//     }

//     @Override
//     public void run() {
//         // 客房服务人员线程
//         while (true) {
//             try {
//                 Thread.sleep(500);
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//             if (this.available) {
//                 continue;
//             }
//             this.available = true;
//         }
//     }
// }

// class Receptionist implements Runnable {
//     private int number;
//     private boolean available;

//     public Receptionist(int number) {
//         this.number = number;
//         this.available = true;
//     }

//     public boolean isAvailable() {
//         return available;
//     }

//     public synchronized void book(Customer customer, int roomType) {
//         // 预定客房
//         while (!this.available) {
//             try {
//                 wait();
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//         }
//         List<Room> rooms = HotelManagement.getInstance().getRooms();
//         for (Room room : rooms) {
//             if (room.isAvailable() && room.getType() == roomType) {
//                 room.checkIn(customer);
//                 System.out.println(
//                         "前台服务员" + this.number + "为顾客" + customer.getName() + "预定了" + room.getNumber() + "号房间");
//                 return;
//             }
//         }
//         System.out.println("前台服务员" + this.number + "为顾客" + customer.getName() + "未找到合适的客房类型");
//     }

//     @Override
//     public void run() {
//         // 前台服务员线程
//         while (true) {
//             try {
//                 Thread.sleep(500);
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//             if (this.available) {
//                 continue;
//             }
//             this.available = true;
//         }
//     }
// }

// class LobbyAttendant implements Runnable {
//     private int number;
//     private boolean available;

//     public LobbyAttendant(int number) {
//         this.number = number;
//         this.available = true;
//     }

//     public boolean isAvailable() {
//         return available;
//     }

//     public synchronized void help(Customer customer) {
//         // 提供帮助
//         while (!this.available) {
//             try {
//                 wait();
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//         }
//         System.out.println("大厅服务员" + this.number + "为顾客" + customer.getName() + "提供帮助");
//         try {
//             Thread.sleep(1000);
//         } catch (InterruptedException e) {
//             e.printStackTrace();
//         }
//         System.out.println("大厅服务员" + this.number + "完成帮助");
//         this.available = false;
//         notifyAll();
//     }

//     @Override
//     public void run() {
//         // 大厅服务员线程
//         while (true) {
//             try {
//                 Thread.sleep(500);
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//             if (this.available) {
//                 continue;
//             }
//             this.available = true;
//         }
//     }
// }
