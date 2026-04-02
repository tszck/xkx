// Room: /d/lingxiao/dadian.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
string look_duilian();
#include <ansi.h>
void create()
{
	set("short", "凌霄殿");
	set("long",
"這裏就是凌霄城的根本之地----凌霄殿。向來，不管凌霄城有何大
事，掌門都會在此召集門人，發號施令。大廳北牆上，掛着一個老人的
肖像，是當年凌霄城創派祖師的遺像。兩邊柱子上刻着一幅對聯(lian)。
旁邊的兵器架上放滿了寒光閃閃的長劍。堂額掛着一張匾，上書四個大
字。"HIB"

                       梅雪凌霄
\n"NOR);
        set("valid_startroom", 1);
	set("item_desc",([
		"lian" : (: look_duilian :),
	]));
	set("exits", ([
		"east"  : __DIR__"fudian2",
		"west"  : __DIR__"fudian1",
		"north" : __DIR__"qianyuan",
		"out"   : __DIR__"meiroad1",
	]));
	set("objects", ([
		__DIR__"npc/lu" : 1,
		__DIR__"npc/dizi" : 3,
	]));
	set("coor/x", -31000);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
	"/clone/board/lingxiao_b"->foo();
}

string look_duilian()
{
	return
	"\n"
	"    **********************************\n"
	"    ********　　　　　　　　  ********\n"
	"    ********　寶          梅　********\n"
	"    ********　劍          花　********\n"
	"    ********　鋒          香　********\n"
	"    ********　自          自　********\n"
	"    ********　磨          苦　********\n"
	"    ********　礪          寒　********\n"
	"    ********　出          來　********\n"
	"    ********　　　　　　　　　********\n"
	"    **********************************\n\n";
}
