//Room: duguangtai.c 睹光臺
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","睹光臺");
      set("long",@LONG
這裏是看日出、雲海、佛光、神燈之地。臺下深崖萬丈，陡徹無底，雲遮
霧掩。極目四望，數百里外的大小雪山皆歷歷在目。
　　金頂雲海，迷迷茫茫，籠罩四野，遠接天際。雲海輕蕩時，你在金頂，腳
踏白雲，大有飄飄欲仙之感；當雲濤迅猛湧來時，整個金頂都似在向前浮動，
令人有乘舟欲風之意。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/bei" : 1,
      ]));
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "north"    : __DIR__"huacangan",
          "west"     : __DIR__"dgtsheshenya", 
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6220);
	set("coor/y", -1170);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}