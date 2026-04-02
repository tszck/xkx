//Room: /d/dali/wumeng.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","烏蒙村落");
	set("long",@LONG
這裏是山的緩坡，烏夷人搬石去土，把這裏修成一層層階梯狀的
平臺，民居分別建在各處平臺上，互不連接，各自有石砌圍牆，村中
道路也由石頭鋪成。
LONG);
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "west"    : __DIR__"wunong",
	    "east"    : __DIR__"caopo",
	    "north"   : __DIR__"wuyiminju1",
	    "south"   : __DIR__"wuyiminju2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -43000);
	set("coor/y", -52000);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}