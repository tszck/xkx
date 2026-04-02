// Room: /d/nanshaolin/zhonglou.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "鐘樓小院");
	set("long", @LONG
這是一座磚木結構的寶塔，塔高七層，塔身作八角形，飛檐翹翎，
檐角上掛滿了一串串小銅鈴，隨風叮叮作響。塔身牆上鏤空雕繪着無數
佛陀們的坐像。一個個形態維肖，看來出自名匠之手。塔底入口處開了
一扇拱形的小木門，門扇兩側用彩漆塗繪，畫的是釋祖在靈山對諸天眾
佛講經時的情形。
LONG );

	set("exits", ([
		"west"  : __DIR__"celang-3",
		"enter" : __DIR__"zhlou1",
	]));
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "enter" ) return 0;
	return ::valid_leave(me, dir);
}

