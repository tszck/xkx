// Room: /d/nanshaolin/wuqiku.c
// Last Modified by winder on May. 29 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "武器庫");
	set("long", @LONG
少林寺的武器庫可稱天下第一，十八般兵器，這裏可謂應有盡有。
四面一望，令你頓感眼花繚亂。牆上砌了一個個小格子，每個都插滿了
各種各樣的兵器。牆角一個健壯的僧人正乒乒乓乓地在打造一根禪杖。
另一位灰衣僧人正在牆角拂拭一把戒刀。看到你進來，他緩緩起身，向
你迎了過來。
LONG );
	set("exits", ([
		"south" : __DIR__"lshuyuan",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangchen" : 1,
		WEAPON_DIR+"sword/zhujian" : 1,
		WEAPON_DIR+"blade/mudao" : 1,
	]));
	set("coor/x", 1790);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

