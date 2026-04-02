// 神話世界·西遊記·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// guihuageng.c 桂花雪蓮羹

inherit ITEM;

void init();
void eat();

void create()
{
   set_name("桂花雪蓮羹",({"guihua geng", "guihua", "geng"}));
   set_weight(50);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "以崑崙山玉女峯頂的桂花與雪蓮製成，對精神大有裨益。\n");
     set("unit", "碗");
     set("value", 800);
        set("remaining", 5);
        set("food_supply", 30);
    }
   
   setup();
}

void init()
{
   add_action("do_chi", "eat");
}


int do_chi(string arg)
{

   int heal, recover, sen, e_sen, m_sen/*,remaining*/;
   
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("你上一個動作還沒有完成。\n");
    if(   (int)this_player()->query("food")
       >= (int)this_player()->max_food_capacity() )
     return notify_fail("你已經喫得太多了，再喫就撐死了。\n");

    this_player()->add("food", (int)query("food_supply"));

    m_sen = (int)this_player()->query("max_sen");
   heal = (int)this_player()->query_con();
    e_sen = (int)this_player()->query("eff_sen");
   
    if ( e_sen < m_sen )
   {    
     if ( (e_sen + heal) >= m_sen )
     {
        this_player()->set("eff_sen", m_sen);
     } else
     {   
        this_player()->add("eff_sen", heal);
     }   
   } 

    e_sen = (int)this_player()->query("eff_sen");
    sen = (int)this_player()->query("sen");
   recover = 30+heal;
    
   if (sen < e_sen )
   {
        if ( (sen + recover) >= e_sen )
        {
            this_player()->set("sen", e_sen);
        } else
        {   
            this_player()->add("sen", recover);
        }   
   }

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
   if ( query("remaining") )
   {
         message_vision("$N拿起一碗桂花雪蓮羹喫了幾口。一股清香直入心脾，$N覺得精神好多了。\n", this_player());
   } else 
   { 
         message_vision("$N把碗裏的桂花雪蓮羹舔得乾乾淨淨，仍是意尤未盡。\n", this_player());
     
     destruct(this_object());
   }

   return 1;
}