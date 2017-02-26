#////////////////////////////////////////////////////////////////////////////
#//   Global makefile
#//
#//   copyright            : (C) 2004 by Lynn Hazan
#//   email                : lynn.hazan@myrealbox.com
#//   copyright            : (C) 2008-2011 by Michael Zugaro
#//   email                : michael.zugaro@college-de-france.fr
#//
#//   This program is free software; you can redistribute it and/or modify
#//   it under the terms of the GNU General Public License as published by
#//   the Free Software Foundation; either version 3 of the License, or
#//   (at your option) any later version.
#//
#////////////////////////////////////////////////////////////////////////////

MAKE = /usr/bin/make --no-print-directory

SRC_DIR = src/
SCRIPTS_DIR = scripts/
DESCRIPTIONS_DIR = descriptions/

all:
	@echo "Making all in $(SRC_DIR)..."; (cd $(SRC_DIR); $(MAKE));
	@echo "Making all in $(SCRIPTS_DIR)..."; (cd $(SCRIPTS_DIR); $(MAKE));

clean:
	@(cd $(SRC_DIR)$$i; $(MAKE) clean);
	@(cd $(SCRIPTS_DIR)$$i; $(MAKE) clean);
	@(cd $(DESCRIPTIONS_DIR)$$i; $(MAKE) clean);

install:
	@(cd $(SRC_DIR); $(MAKE) install);
	@(cd $(SCRIPTS_DIR); $(MAKE) install);
	@(cd $(DESCRIPTIONS_DIR)$$i; $(MAKE) install);

uninstall:
	@(cd $(SRC_DIR); $(MAKE) uninstall);
	@(cd $(SCRIPTS_DIR)$$i; $(MAKE) uninstall);
	@(cd $(DESCRIPTIONS_DIR)$$i; $(MAKE) uninstall);

