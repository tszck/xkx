//Room: /d/dali/yuhuayuan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","御花園");
	set("long",@LONG
這裏是大理國皇宮的御花園，兩旁的花開得爭奇鬥豔，邊上有
一個小水池，山上流下來的泉水就會集在那裏，
幾隻仙鶴在水邊抓魚，一副旁若無人的樣子，
往北是花廊，往南是前殿。
LONG);
	set("objects", ([
	   __DIR__"npc/xianhe": 1,
	]));
	set("outdoors", "daligong");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"hualang",
	    "south"  : __DIR__"qiandian",
	]));
	set("coor/x", -40010);
	set("coor/y", -70970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}