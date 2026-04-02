// Room: /yangzhou/baiyipu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","沈家白衣鋪");
	set("long",@LONG
店內略有些小，幾個人在試看衣服，就顯得很擁擠。邊上有個裁縫，
正給一小夥子量身材。一箇中年男子拿了一套衣服正要去後邊更衣室試
衣服。店雖小，可店內陳列的衣服倒不少，各款式的男女成衣應有盡有。
看來你是能在此挑選到自己喜歡的衣服了。店門口掛着個(paizi)。
LONG );
	
	set("item_desc", ([
		"paizi" : "本店招募燙布小工。\n",
	]));	
	set("exits", ([
		"north" : __DIR__"dashixijie",
		"west"  :__DIR__"shenjiakufang",
	]));
	set("objects", ([
		__DIR__"npc/shenwanfu" : 1,
	]));
	set("coor/x", 55);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}