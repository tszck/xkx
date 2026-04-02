//Room: dgtsheshenya.c 睹光臺捨身崖
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","捨身崖");
      set("long",@LONG
從臥雲庵出來，這裏是看日出、雲海、佛光、神燈之地。臺下深崖萬丈，
陡徹無底，雲遮霧掩。極目四望，數百里外的大小雪山皆歷歷在目。因爲這裏
至高至潔，至險至奇，又至美至幻，常有人在這裏投身雲海，舍此肉身塵世。
　　金頂雲海，迷迷茫茫，籠罩四野，遠接天際。雲海輕蕩時，你在金頂，腳
踏白雲，大有飄飄欲仙之感；當雲濤迅猛湧來時，整個金頂都似在向前浮動，
令人有乘舟欲風之意。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "enter"    : __DIR__"woyunan",
          "east"     : __DIR__"duguangtai", 
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6230);
	set("coor/y", -1170);
	set("coor/z", 190);
	setup();
}
void init()
{
   object me;
   if( interactive( me = this_player())) remove_call_out("clone_ji");
       call_out("clone_ji", 2,me);
   add_action("do_sheshen","sheshen");
}
void clone_ji(object me)
{
   object *ob,obj;
   int i,j;

   j=0;
   ob = all_inventory(environment(me));
   for(i=0; i<sizeof(ob); i++)
   {
      if ( (!userp(ob[i])) && ((string)ob[i]->query("id")=="ji xiaofu"))
      j=1;
   }
   if ((j==0) && (me->query("marks/ji")))
   {
      if( environment(me) == this_object()) obj=new("/kungfu/class/emei/ji.c");
      obj->move(environment(me));
   }
}
int do_sheshen(object me)
{
    me = this_player();
    message_vision("$N覺得活着太沒意思了，決定捨身成仁。\n", me);
    message_vision("$N毅然跳出捨身崖，長聲尖叫，淒厲的聲音響徹山谷，隨着$N的的下落也急劇向下拉長。\n", me);
    if (random(3)==2)
    {
        me->move(__DIR__"st0");
        me->unconcious();
    }
    else
    {
        command("chat 有人跳下捨身崖自殺了。\n\n");
        me->move(__DIR__"st0");
        me->die();
    }
    return 1;
}