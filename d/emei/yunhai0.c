inherit ROOM;
void create()
{
        set("short", "雲海");
        set("long", @LONG
這裏就是峨嵋著名的雲海了，放眼望去，漫山遍野都
是雲霧，根本就弄不清自己身在何出，四周都是出路，什
麼都看不清楚。
LONG   );
	set("coor/x", -6200);
	set("coor/y", -1180);
	set("coor/z", 200);
	setup();
}
void init()
{
  object me = this_object();
  me->set("exits/east",__DIR__"yunhai"+random(3));
  me->set("exits/west",__DIR__"yunhai"+random(3));
  me->set("exits/north",__DIR__"yunhai"+random(3));
  me->set("exits/south",__DIR__"yhrkou");
}