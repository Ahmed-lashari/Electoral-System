# Project Information: Electoral System in C Language

- #### This project constituted our semester assignment at the university, requiring completion within a limited timeframe of 14 days. I collaborated with a fellow team member to fulfill the project requirements.

### 1. Project Structure:

- #### The project is organized into functions, each handling specific aspects such as user authentication, account creation, and admin functionalities.
- ### It includes header files for necessary libraries and custom banner functions to enhance the visual presentation.

### 2. User Account Management:

- #### Users can create accounts with personal details like name, age, qualification, and CNIC (used as a password).
- ### The system checks for duplicate CNICs to ensure unique user identification.

### 3. User Authentication:

- #### Users can log in using their usernames and CNICs, with the system validating the credentials against stored data.
- #### Successful login allows users to proceed to vote for political parties.

### 4. Voting System:

- #### Voters can cast their votes for one of four political parties (PARTY A, PARTY B, PARTY C, PARTY D).
- #### The system records votes and prevents multiple voting by checking against a file of casted voters.

### 5. Admin Panel:

- #### Admins can log in using a predefined username and CNIC.
- #### Admin functionalities include viewing voting results, accessing an audit log, and reviewing details of registered voters.

### 6. Result Display:

- #### The system provides a menu for admins to view voting results for each political party separately.
- #### Results are displayed with detailed information about each vote, such as the voter's name and CNIC.

### 7. Audit Log:

#### The system maintains an audit log file, recording every vote cast by users.

### 8. Data Storage:

#### User details and login information are stored in separate files to maintain organization and facilitate system functionality.

### 9. Program Flow:

#### The main function utilizes a while loop for user menu navigation, providing options for account signup, login, admin login, and program exit.

### 10. Banners and Notifications:

- #### Custom banner functions are used to enhance the visual appeal of different sections, providing a user-friendly interface.
- #### Beep functions are implemented for audio feedback during specific events.

### 11. File Handling:

- #### The project extensively uses file handling to store and retrieve user data, voting results, and admin information.

### 12. Exit Functionality:

- #### The program includes a graceful exit with a bottom banner and beeping sounds for a user-friendly termination experience.
