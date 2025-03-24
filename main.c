/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>

 void initializeSystem(int lights[], int temps[], int motion[], int locks[], int rooms);
 void toggleLight(int lights[], int room);
 void readTemperature(int temps[], int room);
 void checkMotion(int motion[], int room);
 void lockUnlockSecurity(int locks[], int room);
 void houseStatus(int lights[], int temps[], int motion[], int locks[], int rooms);
 
 int main() {
     int rooms;
     printf("Enter number of rooms: ");
     scanf("%d", &rooms);
 
     int lights[rooms], temps[rooms], motion[rooms], locks[rooms];
     initializeSystem(lights, temps, motion, locks, rooms);
     
     int choice, room;
     while (1) {
         printf("\n===== Smart Home Menu =====\n");
         printf("1. Toggle Light\n");
         printf("2. Read Temperature\n");
         printf("3. Check Motion Sensor\n");
         printf("4. Lock/Unlock Security System\n");
         printf("5. House Status Summary\n");
         printf("6. Exit\n");
         printf("Enter your choice: ");
         scanf("%d", &choice);
         
         switch (choice) {
             case 1:
                 printf("Enter room number to toggle light (1-%d): ", rooms);
                 scanf("%d", &room);
                 toggleLight(lights, room - 1);
                 break;
             case 2:
                 printf("Enter room number to read temperature (1-%d): ", rooms);
                 scanf("%d", &room);
                 readTemperature(temps, room - 1);
                 break;
             case 3:
                 printf("Enter room number to check motion (1-%d): ", rooms);
                 scanf("%d", &room);
                 checkMotion(motion, room - 1);
                 break;
             case 4:
                 printf("Enter room number to lock/unlock (1-%d): ", rooms);
                 scanf("%d", &room);
                 lockUnlockSecurity(locks, room - 1);
                 break;
             case 5:
                 houseStatus(lights, temps, motion, locks, rooms);
                 break;
             case 6:
                 printf("Exiting...\n");
                 return 0;
             default:
                 printf("Invalid choice, try again.\n");
         }
     }
     return 0;
 }
 
 void initializeSystem(int lights[], int temps[], int motion[], int locks[], int rooms) {
     for (int i = 0; i < rooms; i++) {
         lights[i] = 0;
         temps[i] = 22 + (i % 5); 
         motion[i] = 0;
         locks[i] = 1;
     }
     printf("System initialized.\n");
 }
 
 void toggleLight(int lights[], int room) {
     lights[room] = !lights[room];
     printf("Light in Room %d is now %s.\n", room + 1, lights[room] ? "ON" : "OFF");
 }
 
 void readTemperature(int temps[], int room) {
     printf("Temperature in Room %d: %d°C\n", room + 1, temps[room]);
 }
 
 void checkMotion(int motion[], int room) {
     printf("Motion in Room %d: %s\n", room + 1, motion[room] ? "Detected" : "No Motion");
 }
 
 void lockUnlockSecurity(int locks[], int room) {
     locks[room] = !locks[room];
     printf("Room %d is now %s.\n", room + 1, locks[room] ? "Locked" : "Unlocked");
 }
 
 void houseStatus(int lights[], int temps[], int motion[], int locks[], int rooms) {
     printf("\nHouse Status:\n");
     for (int i = 0; i < rooms; i++) {
         printf("- Room %d: Light %s, Temp %d°C, %s, %s\n", i + 1,
                lights[i] ? "ON" : "OFF",
                temps[i],
                motion[i] ? "Motion Detected" : "No Motion",
                locks[i] ? "Locked" : "Unlocked");
     }
 }
 