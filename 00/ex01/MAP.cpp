#include "MAP.hpp"

int main()
{
	std::string command;
	int flag = 1;
	PhoneBook pb = PhoneBook();
	std::cout<<"███╗   ███╗██╗   ██╗     █████╗ ██╗    ██╗███████╗███████╗ ██████╗ ███╗   ███╗███████╗    ██████╗ ██╗  ██╗ ██████╗ ███╗   ██╗███████╗██████╗  ██████╗  ██████╗ ██╗  ██╗\n"
			  "████╗ ████║╚██╗ ██╔╝    ██╔══██╗██║    ██║██╔════╝██╔════╝██╔═══██╗████╗ ████║██╔════╝    ██╔══██╗██║  ██║██╔═══██╗████╗  ██║██╔════╝██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝\n"
			  "██╔████╔██║ ╚████╔╝     ███████║██║ █╗ ██║█████╗  ███████╗██║   ██║██╔████╔██║█████╗      ██████╔╝███████║██║   ██║██╔██╗ ██║█████╗  ██████╔╝██║   ██║██║   ██║█████╔╝ \n"
			  "██║╚██╔╝██║  ╚██╔╝      ██╔══██║██║███╗██║██╔══╝  ╚════██║██║   ██║██║╚██╔╝██║██╔══╝      ██╔═══╝ ██╔══██║██║   ██║██║╚██╗██║██╔══╝  ██╔══██╗██║   ██║██║   ██║██╔═██╗ \n"
			  "██║ ╚═╝ ██║   ██║       ██║  ██║╚███╔███╔╝███████╗███████║╚██████╔╝██║ ╚═╝ ██║███████╗    ██║     ██║  ██║╚██████╔╝██║ ╚████║███████╗██████╔╝╚██████╔╝╚██████╔╝██║  ██╗\n"
			  "╚═╝     ╚═╝   ╚═╝       ╚═╝  ╚═╝ ╚══╝╚══╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝    ╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝"<<std::endl;
	while (1)
	{
		if (flag == 1)
			pb.add_print("명령을 입력해주세용 ex)ADD, SEARCH, EXIT ...", &command);
		if (flag == 0)
			pb.add_print("세 명령어만 입력 가능합니다..", &command);
		if (command == "ADD")
		{
			if (pb.add())
				break;
			flag = 1;
		}
		else if(command == "SEARCH")
		{
			pb.search();
			flag = 1;
		}
		else if(command == "EXIT")
			break;
		else
			flag = 0;
	}
}
