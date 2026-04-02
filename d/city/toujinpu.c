// Room: /yangzhou/toujinpu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","孔家頭巾鋪");
	set("long",@LONG
孔家做的頭巾帽子，花樣繁多，式樣也漂亮，揚州城的年輕人多到
此挑選一條自己喜歡的頭巾。店內東邊放置一張胡牀，上面放滿了各式
的頭巾帽子，客人可以隨便試着穿戴各式頭巾帽子；西邊放着幾面銅鏡，
幾個小夥子正在邊試戴各式頭巾，邊照鏡子。
LONG );
	set("exits", ([
		"north" : __DIR__"caiyixijie",
	]));
	set("objects", ([
		__DIR__"npc/kongjinjin" : 1,
	]));
	set("coor/x", 50);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}