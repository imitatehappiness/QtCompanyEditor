<p align="center">
  <a href="https://github.com/imitatehappiness/QtCompanyEditor">
      <img width="128" alt="multiple-users-silhouette" src="https://user-images.githubusercontent.com/79199956/222869352-28a2fac7-4ed4-48aa-ae78-b46c0946321a.png">
  </a>
  <h3 align="center"></h3>
</p>

# Company Editor

This C++ Qt application allows users to manage departments and employees of a company. Users can add, delete, and edit departments and employees through an intuitive graphical user interface. The application also supports saving and reading data using an XML file for persistent storage.

## Features
+ Add new departments and employees: Users can easily create new departments and add employee information, such as name, position, and contact details.
+ Edit existing departments and employees: The application allows users to update department information and modify employee details.
+ Delete departments and employees: Users have the option to remove departments and employees from the company records.
+ Save and load data: The application supports exporting all the company data to an XML file for safekeeping and importing data from a previously saved XML file.

>**Compiler:**  MinGW 5.3.0 32bit
>
>**Profile Qt:**  5.11.0 MinGW 32bit

## Example XML file
```xml
<?xml version="1.0" encoding="UTF-8"?>
<departments>
	<department name="Administration">
		<employments>
			<employment>
				<surname>Thackeray</surname>
				<name>William</name>
				<middlename>Makepeace</middlename>
				<function>Network Administration</function>
				<salary>1050</salary>
			</employment>
			<employment>
				<surname>London</surname>
				<name>Jack</name>
				<middlename>Makepeace</middlename>
				<function>System Administration</function>
				<salary>1450</salary>
			</employment>
		</employments>
	</department>
	<department name="Promotion">
		<employments>
			<employment>
				<surname>Christie</surname>
				<name>Agatha </name>
				<middlename>Mary Clarissa</middlename>
				<function>IT Management</function>
				<salary>1200</salary>
			</employment>
			<employment>
				<surname>Brown</surname>
				<name>Caleb</name>
				<middlename>Arthur</middlename>
				<function>Planning</function>
				<salary>890</salary>
			</employment>
		</employments>
	</department>
</departments>
```
## Usage example

https://user-images.githubusercontent.com/79199956/222880470-9dd9eac8-a8b8-4882-b721-60683f53bccc.mp4

