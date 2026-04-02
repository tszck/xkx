// Room: /d/nanshaolin/xianglu.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "香爐");
	set("long",@LONG
走過石板路就到了寺內最大的香爐旁，此香爐由青銅鑄就，有兩人
多高爐鼎上精工鏤刻了多種瑞獸及代表祥和超脫的佛家典故。爐內青煙
嫋嫋，端的是佛家無上之寶。爐前香案前，幾位香客正自頂禮膜拜。
LONG );
	set("outdoors", "nanshaolin");
	set("exits", ([
		"north" : __DIR__"stoneroad2",
		"south" : __DIR__"sblu-1",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/yuanbei" : 1,
		__DIR__"npc/xiang-ke" : 2,
	]));
	set("coor/x", 1820);
	set("coor/y", -6250);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

