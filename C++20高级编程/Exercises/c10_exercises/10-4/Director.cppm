export module director;

import employee;
import <string>;
import <format>;

export namespace HR
{
	class Director : public Employee
	{
	public:
		// Explicitly inherit Employee's constructors.
		using Employee::Employee;

		// Constructor to convert from Employee to Director.
		Director(const Employee& employee)
			: Employee{ employee }
		{
		}

		std::string toString() const override
		{
			return std::format("Director is {}", Employee::toString());
		}
	};
}
