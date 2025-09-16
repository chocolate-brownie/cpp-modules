[1mDefault constructor called[0m

-------- Use of DEFAULT constructor --------
[32mMember 1 Info[0m

Name: Default
Hit Points: 10
Energy Points: 10
Attack Damage: 0


-------- Use of NAME constructor --------
[1mName constructor called[0m
[32mMember 2 Info[0m

Name: ClapperTrapper
Hit Points: 10
Energy Points: 10
Attack Damage: 0

-------- Use of COPY constructor --------
[1mName constructor called[0m
[32mMember 3 Info[0m

Name: Christoph
Hit Points: 10
Energy Points: 10
Attack Damage: 0


[1mCopy constructor called[0m
[32mMember 4 Info[0m

Name: Christoph
Hit Points: 10
Energy Points: 10
Attack Damage: 0


-------- Use of COPY ASSIGNMENT OPERATOR --------
[1mName constructor called[0m
[32mObj1 Info[0m

Name: Clappy
Hit Points: 10
Energy Points: 10
Attack Damage: 0

[1mName constructor called[0m
Obj2's name before calling copy assignment operator: CoppyCat
[34mCalling copy assignment operator, copies obj1's data into obj2
[1mCopy assignment operator called[0m
[32mObj2 Info[0m

Name: Clappy
Hit Points: 10
Energy Points: 10
Attack Damage: 0


-------- TESTING MEMBER FUNCTIONS --------

[31mClapTrap ClapperTrapper is taking 5 damage... 5 HP remaining![0m

Name: ClapperTrapper
Hit Points: 5
Energy Points: 10
Attack Damage: 0

[32mClapTrap ClapperTrapper repairs... 8 HP remaining[0m

Name: ClapperTrapper
Hit Points: 8
Energy Points: 9
Attack Damage: 0


[31mClapTrap ClapperTrapper took 10 damage and has died.[0m

Name: ClapperTrapper
Hit Points: 0
Energy Points: 9
Attack Damage: 0

[31mUnable to repair because ClapTrap is dead.[0m

Name: ClapperTrapper
Hit Points: 0
Energy Points: 9
Attack Damage: 0



-------- TESTING SCAVTRAP --------
[1mName constructor called[0m
[1mScavTrap NAME constructor called for Scavvy[0m

[32mScavTrap Scavvy attacks a training dummy, causing 20 points of damage![0m

[31mClapTrap Scavvy is taking 30 damage... 70 HP remaining![0m
[32mClapTrap Scavvy repairs... 80 HP remaining[0m
[34mScavTrap is now in Gate keeper mode.[0m

[31mClapTrap Scavvy took 100 damage and has died.[0m

Name: Scavvy
Hit Points: 0
Energy Points: 48
Attack Damage: 20

[31mScavTrap Scavvy can't act![0m


-------- TESTING FRAGTRAP --------
[1mName constructor called[0m
[1mFragTrap NAME constructor called for Fraggy[0m

[32mFragTrap Fraggy attacks a rusty car, causing 30 points of damage![0m

[31mClapTrap Fraggy is taking 50 damage... 50 HP remaining![0m
[32mClapTrap Fraggy repairs... 75 HP remaining[0m
[34mHigh Five!!![0m

[31mClapTrap Fraggy took 100 damage and has died.[0m

Name: Fraggy
Hit Points: 0
Energy Points: 98
Attack Damage: 30

[31mFragTrap Fraggy can't act![0m


-------- TESTING DIAMONDTRAP --------
[1mName constructor called[0m
[1mScavTrap DEFAULT constructor called[0m
[1mFragTrap DEFAULT constructor called[0m
[35m[1mDiamondTrap DEFAULT constructor called for Default[0m
[1mName constructor called[0m
[1mScavTrap NAME constructor called for I am Diamond 2_clap_name[0m
[1mFragTrap NAME constructor called for I am Diamond 2_clap_name[0m
[35m[1mDiamondTrap NAME CONSTRUCTOR is called for I am Diamond 2[0m

Name: Default_clap_name
Hit Points: 100
Energy Points: 100
Attack Damage: 30


[32mScavTrap Default_clap_name attacks sapphire, causing 30 points of damage![0m

[31mClapTrap Default_clap_name is taking 26 damage... 74 HP remaining![0m
[32mClapTrap Default_clap_name repairs... 85 HP remaining[0m
[36mMy DiamondTrap name is: Default[0m
[36mMy ClapTrap name is: Default_clap_name[0m

[31mClapTrap Default_clap_name is taking 3 damage... 82 HP remaining![0m

Name: Default_clap_name
Hit Points: 82
Energy Points: 98
Attack Damage: 30


[32mScavTrap Default_clap_name attacks blue sapphire, causing 30 points of damage![0m
[1mCopy assignment operator called[0m
[35m[1mDiamondTrap COPY ASSIGNMENT OPERATOR called[0m

Name: Default_clap_name
Hit Points: 82
Energy Points: 97
Attack Damage: 30

[35m[1mDiamondTrap DESTRUCTOR is called for Default[0m
[1mFragTrap destructor called for Default_clap_name[0m
[1mScavTrap destructor called for Default_clap_name[0m
[1mClapTrap destructor called for Default_clap_name[0m
[35m[1mDiamondTrap DESTRUCTOR is called for Default[0m
[1mFragTrap destructor called for Default_clap_name[0m
[1mScavTrap destructor called for Default_clap_name[0m
[1mClapTrap destructor called for Default_clap_name[0m
[1mFragTrap destructor called for Fraggy[0m
[1mClapTrap destructor called for Fraggy[0m
[1mScavTrap destructor called for Scavvy[0m
[1mClapTrap destructor called for Scavvy[0m
[1mClapTrap destructor called for Clappy[0m
[1mClapTrap destructor called for Clappy[0m
[1mClapTrap destructor called for Christoph[0m
[1mClapTrap destructor called for Christoph[0m
[1mClapTrap destructor called for ClapperTrapper[0m
[1mClapTrap destructor called for Default[0m
