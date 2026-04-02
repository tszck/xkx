// /guanwai/xuedi3.c

inherit ROOM;

void create()
{
	set("short", "雪地");
	set("long", @LONG
這裏是一片白茫茫的雪地，一眼望不到邊際。四周一個人影也沒有，
厚厚的積雪踩起來發出咯吱的響聲，大地上留下一串孤獨的腳印。寒冷
的北風呼嘯而過，吹得臉生痛。暗淡的太陽低懸在天邊，顯得那麼蒼白。
LONG );
	set("exits", ([
		"north"  : __DIR__"chuanchang",
		"west"   : __DIR__"xuedi2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	set("coor/x", 6080);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	me->receive_damage("qi",30);
	me->receive_wound("qi",30);
	tell_object(me,"一股刺骨的寒風吹過，你只覺得渾身的血液都快被凍住了！\n");
	return 1;
}