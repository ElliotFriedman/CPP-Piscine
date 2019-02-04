#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

#include <string>
#include "IMonitorModule.hpp"

class   IMonitorModule {
    public:
        IMonitorModule(void);
        ~IMonitorModule(void);
        virtual std::string data(void) = 0;
		bool	displayModule(void);
		bool	getDisplay(void);
		void	setDisplay(bool);
		int		getOffset(void);

	protected:
		int	offset;

	private:
		bool display;

};

#endif
