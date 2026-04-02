// Room: /d/heimuya/restroom.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","休息室");
	set("long", @LONG
這裏是間休息室，裏面有張大牀。在這裏睡覺非常舒服，沒人能打
擾。南面是氣派的長廊。
LONG );
	set("exits",([
		"east" : __DIR__"houting",
	]));
	set("sleep_room", 1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_clean_up", 0);
	set("coor/x", -3260);
	set("coor/y", 4210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
