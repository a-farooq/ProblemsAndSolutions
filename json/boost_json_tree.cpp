#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>

int main() {
	using boost::property_tree::ptree;

	//std::ifstream jsonFile("input.txt");
	//std::string jsonstr = "{ \"Groups\":\"\"}";
	std::string jsonstr2 = "{\"Groups\":[{\"ID\":\"1\", \"Type\" : \"1\", \"Name\" : \"g1\", \"Description\" : \"g1\", \"CreationDate\" : \"11\/03\/20\"}, { \"ID\":\"2\",\"Type\" : \"1\",\"Name\" : \"g2\",\"Description\" : \"g2\",\"CreationDate\" : \"14\/03\/20\" }]}";
	std::string str1 = "[{\"number\": 1234, \"string\" : \"hello world\"}, { \"number\": 5678, \"string\" : \"foo bar\" }]";
	//{\"number\": 1234, \"string\" : \"hello world\", \"ID\": \"A1\"}
	//std::stringstream ss; 
	//ss << str1;
	//ss << jsonstr2;

	ptree pt;
	
	//read_json(ss, pt);

	//std::stringstream jsonStream(jsonstr2);
	std::stringstream jsonStream(str1);
	read_json(jsonStream, pt);
	//std::string desc = pt.get<std::string>("GroupID");
	//pt = pt.get_child("Groups");

	if (pt.empty())
	{
		std::cout << "Empty" << "\n";
	}
	else
	{
		std::cout << "Not Empty" << "\n";
	}

	//auto gid = pt.find("GroupID");
	//std::cout << gid->second << "\n";
	//std::string desc = pt.get<std::string>("Description");

	for (auto & array_element : pt) {
		//int num = array_element.second.get<int>("number");
		//std::cout << num << "\n";
		//std::string num_str = "1234";
		//boost::property_tree::ptree childNode;
		//childNode.add_child()
		//array_element.a
		for (auto & property : array_element.second) {
			
			//if (stoi(num_str) == num)
				//std::cout << property.first << " = " << property.second.get_value < std::string >() << "\n";
		}
		array_element.second.put("ID", 213);
		array_element.second.erase("number");
	}

	for (auto & array_element : pt) {
		for (auto & property : array_element.second) {
			std::cout << property.first << " = " << property.second.get_value < std::string >() << "\n";
		}
	}

	for (auto element : pt)
	{
		boost::property_tree::ptree child = element.second;

		int id = child.get<int>("ID");

		std::cout << id << "\n";
	}

	std::string s1 = "";
	int t1 = 14;

	while (t1)
	{
		t1 & 1 ? s1.append("1") : s1.append("0");
		t1 >>= 1;
	}
	std::reverse(std::begin(s1), std::end(s1));

	std::cout << s1 << "\n";
}

int main2()
{
	try
	{
		std::stringstream ss;
		//ss << "{ \"root\": { \"values\": [1, 2, 3, 4, 5 ] } }";
		
		//std::string jsonstr = "{ \"Groups\": [1, 2, 3, 4, 5 ] }"; //, \"2\", \"3\", \"4\", \"5\"
		//std::string jsonstr = "{ \"Groups\":[{\"a\":\"1\", \"b\":\"2\"}] }";
		//std::string jsonstr = "{ \"Groups\":\"\"}";
		std::string jsonstr = "{ \"Groups\":[{\"ID\":\"1\",\"Type\" : \"1\",\"Name\" : \"g1\",\"Description\" : \"g1\",\"CreationDate\" : \"12\/03\/20\"}] }";
		ss << jsonstr;

		boost::property_tree::ptree pt;
		boost::property_tree::read_json(ss, pt);

		//boost::property_tree::ptree gp = pt.get_child("Groups");
		std::string gstr = (pt.get_child("Groups")).data();
		//std::string s = gp.get_value<std::string>("GroupID");

		//BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("Groups"))
		//{
		//	//assert(v.first.empty()); // array elements have no names
		//	std::cout << v.second.data() << std::endl;
		//}
		return EXIT_SUCCESS;
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return EXIT_FAILURE;
}
