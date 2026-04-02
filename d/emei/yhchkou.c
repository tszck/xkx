inherit ROOM;
void create()
{
        set("short", "雲海出口");
        set("long", @LONG
這裏就是峨嵋著名的雲海了，放眼望去，漫山遍野都
是雲霧，根本就弄不清自己身在何出。在霧中隱隱約約有
一條瀑布夾霧而下！
LONG  );
        set("exits",([
          "north": __DIR__"pubu",
          "south": __DIR__"yunhai12",
        ]));
	set("coor/x", -6200);
	set("coor/y", -1170);
	set("coor/z", 200);
	setup();
        replace_program(ROOM);
}