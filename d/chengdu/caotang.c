// Room: /d/chengdu/caotang.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "杜甫草堂");
	set("long", @LONG
這裏是杜甫流寓成都的故居。草堂裏流水回縈，小橋勾連，竹樹
掩映，顯得既莊嚴肅穆，古樸典雅，又不失幽深靜謐，秀麗清朗。
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
		"south" : __DIR__"baihuatan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8090);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
