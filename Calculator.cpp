//GPA calculator for ASU-science

#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;
#define  t "\t\t";

struct course {
	string name, rank;
	int  credits;
	float gpa,grade;
	course(string Cname, int Ccredits, float Cgrade) {
		name = Cname; credits = Ccredits; grade = Cgrade;
		gpa = calcCGPA();
	}
	float calcCGPA() {
		float n = grade / (credits * 0.5);
		if (n >= 90) { rank = 'A'; gpa = 4; }
		else if (n >= 85) { rank = "A-";gpa = 3.67; }
		else if (n >= 80) { rank = "Β+";gpa = 3.33; }
		else if (n >= 75) { rank = 'B';	gpa = 3.00; }
		else if (n >= 70) { rank = "C+";gpa = 2.67; }
		else if (n >= 65) { rank = 'C';	gpa = 2.33; }
		else if (n >= 60) { rank = 'D';	gpa = 2.00; }
		else { rank = 'F'; gpa = 0; }
		return gpa;
	}
	void gpa2rank() {
		float n = grade / (credits * 0.5);
		if (n >= 4) { rank = 'A'; }
		else if (n >= 3.67) { rank = "A-";}
		else if (n >= 3.33) { rank = "Β+";}
		else if (n >= 3.00) { rank = 'B'; }
		else if (n >= 2.67) { rank = "C+";}
		else if (n >= 2.33) { rank = 'C'; }
		else if (n >= 2.00) { rank = 'D'; }
		else { rank = 'F';}
	}
	void display() {
		cout << name << t;
		cout << credits << t;
		cout << grade << t;
		cout << rank << "\n";
	}
};
void pastSem(float& nomerator, int& Tcredits) {
	char ans;
	cout << "Do you want to calculate the total GPA or a semester GPA?\na)Yes\tb)No\n"; cin >> ans;
	if (ans == 'a' || ans == 'y' || ans == 'Y')
	{
		float gpa; int credits;
		cout << "Insert the total GPA for the past semesters : "; cin >> gpa;
		cout << "Insert the total credit hours for the past semesters : "; cin >> credits;
		nomerator += gpa * credits;
		Tcredits += credits;
	}
	else if (ans == 'b' || ans == 'n' || ans == 'N')
		return;
	else
	{
		cout << "Invalid insert!\nPlease insert a valid character\n\n"; pastSem(nomerator,Tcredits);
	}
}
string message(float gpa) {
	int i;
	srand((int)gpa);
	i = rand() % 10;
	string quote[4][10] =
	{
		"You rock!","Top tier!","On fire!","So smart!","Ace mode","Too easy","Wow, A!","Nailed it","Brainy!","Slayed!",
		"Keep it up!","Nice try!","You got it!","So close!","Not bad!","Push more","Stay cool","Keep grind","Halfway!","Try hard!",
		"U got this","Next time!","Don’t quit","Try again","Head up!","Go harder","Fix this","Be brave","You can!","One shot!",
		"Wake up!","Yikes!","Do work!","KYS","Low batt","GPA who?","Help?","Oof...","Fix it!","Come on!" 
	};
	if (gpa >= 3.5) return quote[0][i];
	else if (gpa >= 2.5) return quote[1][i];
	else if (gpa >= 1.0) return quote[2][i];
	else return quote[3][i];
}
int main() {
	int num, credits;
	float grade,nomerator = 0;
	int totalcredits = 0;
	int totalpassed ;
	string name;
	vector<course> C;
	pastSem(nomerator, totalcredits);
	totalpassed = totalcredits;
	cout << "Insetrt the number of courses for the semster : "; cin >> num;
	for (int i = 0; i < num; i++) {
		cout << "Course " << i + 1 << endl;
		cout << "  Insert the course's name : ";	cin >> name;
		cout << "  Insert the course's credit hours : ";	cin >> credits;
		cout << "  Insert the course's degree : ";	cin >> grade;
		C.push_back({ name,credits,grade });
		totalcredits += credits;
	}
	cout << "Name" << t;
	cout << "Credits" << t;
	cout << "Degree" << t;
	cout << "Grade" << "\n";

	for (auto it : C) {
		nomerator += it.credits * it.gpa;
		if (it.gpa != 0) totalpassed += it.credits;
		it.display();
	}
	C.push_back({ "Final\nGrade", totalcredits,nomerator/2 });
	cout << "\n";
	cout << C.back().name << t;
	cout << totalpassed << t;
	cout << nomerator/totalcredits << t;
	C.back().gpa2rank();
	cout << C.back().rank << t;
	cout << message(C.back().gpa) << "\n";
	return 0;
}
