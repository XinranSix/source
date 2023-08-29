export module person;

import <string>;
import <format>;

export class Person
{
public:
	// Two-parameter constructor automatically creates initials and
	// delegates the work to the three-parameter constructor.
	Person(std::string firstName, std::string lastName)
		: Person{ std::move(firstName), std::move(lastName),
		std::format("{}{}", firstName[0], lastName[0]) }
	{
	}

	Person() = default;

	Person(std::string firstName, std::string lastName, std::string initials)
		: m_firstName{ std::move(firstName) }
		, m_lastName{ std::move(lastName) }
		, m_initials{ std::move(initials) }
	{
	}

	const std::string& getFirstName() const { return m_firstName; }
	void setFirstName(std::string firstName) { m_firstName = std::move(firstName); }

	const std::string& getLastName() const { return m_lastName; }
	void setLastName(std::string lastName) { m_lastName = std::move(lastName); }

	const std::string& getInitials() const { return m_initials; }
	void setInitials(std::string initials) { m_initials = std::move(initials); }

	bool operator==(const Person& other) const
	{
		return getFirstName() == other.getFirstName() &&
			getLastName() == other.getLastName() &&
			getInitials() == other.getInitials();
	}

	bool operator!=(const Person& other) const
	{
		return !(*this == other);
	}

	bool operator<(const Person& other) const
	{
		return (getFirstName() < other.getFirstName()) ||

			(getFirstName() == other.getFirstName() &&
				getLastName() < other.getLastName()) ||

			(getFirstName() == other.getFirstName() &&
				getLastName() == other.getLastName() &&
				getInitials() < other.getInitials());
	}

	bool operator>(const Person& other) const
	{
		return other < *this;
	}

	bool operator<=(const Person& other) const
	{
		return *this == other || *this < other;
	}

	bool operator>=(const Person& other) const
	{
		return *this == other || *this > other;
	}

private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_initials;
};
