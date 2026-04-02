// perform.c
// modified by sega 99/1/16
// 添加比武perform限制，參考/d/city/npc/referee.c modified by sega 2000/02/05
// 鬥轉星移
// hubo出雙重pfm by qingyun 04/9/25
//inherit F_CLEAN_UP;lijia
inherit F_SSERVER;

#include <ansi.h>


string *prep_skl = ({"finger","hand","cuff","claw","strike","unarmed","leg"});
private int do_perform(object me, string arg);

int main(object me, string arg)
{
	string and;//第二個pfm
	int result;
//int busy;
  int lvl;
//int suc;
  string msg="\n";
	object target;
	seteuid(getuid());

	if( me->is_busy() )
			return notify_fail("( 你上一個動作還沒有完成，不能施用外功。)\n");
//	if ( environment(me)->is_chat_room())
//      return notify_fail("這裏禁止打鬥。\n");
	if( !living(me) || me->query_temp("noliving") )
			return notify_fail("你行將暈倒，無法施用外功。\n");
	if (me->query("jing") < 0 || me->query("qi") < 0)
			return notify_fail("你行將暈倒，無法施用外功。\n");
	if( me->query_temp("bixie/ciwan") )
			return notify_fail("你的手腕受傷，不能施用外功。\n");
	if( me->query_temp("dagou/feng") )
			return notify_fail("你的招式被打狗棒封住，不能施用外功。\n");
	if( !arg ) 
			return notify_fail("你要用外功做什麼？\n");
  if (me->query_temp("no_perform"))
    	return notify_fail(HIR "你只覺全身力道竟似渙散了一般，全然無法控制。\n" NOR);

//比武perform限制
	
	if (me->query_temp("biwu/perform_time"))
	{
		if (time()-(int)me->query_temp("biwu/perform_time")<8+random(3))
	 	{
			me->start_busy(1+random(2));
			if (target = offensive_target(me))
			{
				message_combatd(HIY"$P剛要使出本門絕技，不想 $p早有準備，先發制人，一陣急攻令$P手忙腳亂。\n"NOR,me,target);
				if (!target->is_busy())
					COMBAT_D->do_attack(target,me,target->query_temp("weapon"), 0);
			}
			return 1;
		}
		write("呵呵。\n");
		me->set_temp("biwu/perform_time",time());
	}
	//判斷開始出pfm
/////////add from here/////////////////
  if (sscanf(arg, "%s and %s", arg, and) == 2)
      {
       lvl = me->query_skill("hubo", 1);
       if (! lvl)
       		return notify_fail("你要幹什麼？以為自己有三頭六臂啊！\n");

       if (me->query_skill("qimen-wuxing", 1))
          return notify_fail("你雜學太多，心頭煩亂，難以分心二用。\n");
       if (lvl <= 100)
          return notify_fail("你的左右互搏修為太淺，難以分心二用。\n");
       if (! me->is_fighting())
          return notify_fail("只有戰鬥中才能施展左右互搏。\n");
       if (lvl < 250 && random(lvl) < 70)
          {
          me->start_busy(2);
          message_combatd("$N試圖分心二用，但是手就是不聽使喚。\n",me);
          return 1;
          }
       }
       result = do_perform(me, arg);//出一招pfm
	if (me->query_temp("murong/xingyi")) me->delete_temp("murong/xingyi");
       if (! and || (me->query("int")>=25 && random(lvl)<150))
            return result; //如果沒有第二招 那麼結束
        if (! result)
//						write(me->query_temp("notify_fail"));
//嗚嗚 沒有query_notify_fail()這個函數  只好用自己的描述了
				  message_combatd(HIY"$N招式未老，身形鬥轉，忽然變招。\n\n"NOR, me);
        else
        {
          switch (random(4))
          	    {
               case 0:
                        msg += HIY "$N" HIY "大喝一聲，雙手分"
                              "使兩招，一起攻出。\n" NOR;
                        break;

                case 1:
                        msg += HIY "$N" HIY "雙手齊出，分使不"
                              "同招式，令人眼花繚亂。\n" NOR;
                        break;

                case 2:
                        msg += HIY "$N" HIY "左右手分使兩招，"
                              "毫不停滯，宛如兩人同時攻出。\n" NOR;
                        break;

                case 3:
                        msg += HIY "$N" HIY "左手一招，右手一"
                              "招，兩招來路各異，令人難以低檔！\n" NOR;
                        break;
                }
								msg += "\n";
                message_combatd(msg, me);
        }
//from here
//怎麼處理的兩次的busy? 
//        busy = me->query_busy();
//        me->interrupt_busy(0);
//        if (intp(busy) && intp(me->query_busy()) &&
//            busy > me->query_busy())
//        {
//                me->interrupt_busy(0);
//               me->start_busy();
//       }
        result = do_perform(me, and); //出第二招pfm
	if (me->query_temp("murong/xingyi")) me->delete_temp("murong/xingyi");
				return result;
//        if (! result)
//						return 0;
//                write(query_notify_fail());

//        return 1;
/////////add finish///////////////
}
private int do_perform(object me, string arg)
{	
	object weapon, target;
	string martial, skill/*,pfarg, uarg, parg*/;
	int result,i,j,ap,dp,plvl,xlvl;

	object tweapon;
	mapping /*skl,*/ pre_skl;
	string *sskl, *file, skname, sktype, skpf, msg;
	target = offensive_target(me);
	if( sscanf(arg, "%s.%s", martial, arg)!=2 )
	{
		if( weapon = me->query_temp("weapon") )
			martial = weapon->query("skill_type");
		else martial = "unarmed";
	}
/*
	if ( userp(me) )
	     if( !wizardp(me) )
	{
		if( sscanf(arg, "%s %s", parg, uarg)==2 )
		{
			pfarg = "perform/" + parg;
			if( me->query(pfarg,1)<1 )
				return notify_fail("你必須先向貴派掌門請教如何運用這門外功。\n");
		}
//		else if( sscanf(arg, "%s.%s", martial, parg)==2 )
//		{
//			pfarg = "perform/" + parg;
//			if( me->query(pfarg,1)<1 )
//				return notify_fail("你必須先向貴派掌門請教如何運用這門外功。\n");			
//		}
		else 
		{
			pfarg = "perform/" + arg;
			if( me->query(pfarg,1)<1 )
				return notify_fail("你必須先向貴派掌門請教如何運用這門外"+arg+"。\n");
		}		
	}*/
	if (!stringp(me->query_skill_mapped("force")))
		return notify_fail("沒有任何內功做為基礎，是發揮不出招式威力的。\n");
	if( martial == "parry" && arg != "xingyi")
		return notify_fail( "不能用基本招架出手外功。\n");
	if( !me->query_temp("weapon") && martial!="unarmed" &&
		martial!="parry" && martial!="dodge")
	{
		pre_skl = me->query_skill_prepare();
		if( !pre_skl ) 
			return notify_fail( "請先用 prepare 指令準備你要使用的外功。\n");
		else
		{
			sskl = keys(pre_skl);
			j = 0;
			for( i=0; i<sizeof(sskl); i++)
				if( martial == sskl[i]) j=1;
			if( j == 0)
				return notify_fail( "你只能使用已經用 prepare 指令準備好的武功的外功。\n");
		}
	}
/* 以下是正常出手 */
	if( me->query_temp("lonely-sword/pozhang") && 
	member_array(martial,prep_skl)!=-1 )
			return notify_fail(HIR"你的手掌受傷，手裏使不上勁。\n"NOR);
	if (arg != "xingyi")
	{
		if( stringp(skill = me->query_skill_mapped(martial)) )
		{
			notify_fail("你所使用的外功中沒有這種功能。\n");
			if( SKILL_D(skill)->perform_action(me, arg) )
			{
				if( random(120) < (int)me->query_skill(skill) )
					me->improve_skill(skill, 1, 1);
				return 1;
			} else
				if( SKILL_D(martial)->perform_action(me, arg) )
				{
					if( random(120) < (int)me->query_skill(martial, 1) ) me->improve_skill(martial, 1, 1);
					return 1;
				}
				return 0;
		}
		return notify_fail("請先用 enable 指令選擇你要使用的外功。\n");
	}
/* 以下為鬥轉星移 */
	else
	{
		me->clean_up_enemy();
		target = me->select_opponent(); 

		if (martial != "parry" ||
			me->query_skill_mapped("parry") != "douzhuan-xingyi")
			return notify_fail("你所使用的外功中沒有這種功能。\n");
		if (me->query("neili") < 500)
			return notify_fail("你內力不夠，不能使用「星移」！\n");
		plvl = me->query_skill("parry",1);
		if( plvl < 120)
			return notify_fail("基本招架未熟練，怎能「星移」？\n");
		xlvl = me->query_skill("douzhuan-xingyi",1);
		if( xlvl < 120)
			return notify_fail("鬥轉星移不熟練，無法「星移」！\n");
		if( me->query_skill("shenyuan-gong",1) < 120)
			return notify_fail("神元功不精熟，也無法「星移」！\n");
		if( !(me->is_fighting() ))
			return notify_fail("「星移」只能在戰鬥中使用。\n");

		target = offensive_target(me);
		if( !target->is_character() )
			return notify_fail("看清楚一點，那並不是生物。\n");
		if (!living(target) || target->query_temp("noliving") )
			return notify_fail(target->name()+ "已經沒知覺了，你用不了對方的力道了。\n"); 

		msg = HIG"$N運起神元功，一口真氣自丹田猛地提了上來！\n"NOR;
		message_combatd(msg,me,target);
/* 出手有兵器，則使用其兵器的perform */
		if( objectp(weapon = me->query_temp("weapon")))
		{
			sktype = weapon->query("skill_type"); 
			if( !objectp(tweapon = target->query_temp("weapon")) ||
				sktype != tweapon->query("skill_type") ) 
					return notify_fail(HIR"你和"+target->query("name")+"沒有持相同類型的兵器，沒法「星移」。\n"NOR); 
			else
			{
				if( me->query_skill(sktype,1) < 120) 
					return notify_fail(HIR"你的"+to_chinese(sktype)+"修為太淺，沒法使用「星移」。\n"NOR); 
				skname = target->query_skill_mapped(sktype);
				if( skname == "murong-sword" ||
					skname == "murong-blade")
					return notify_fail(HIR+target->query("name")+"深諳慕容世家的功夫，你沒法使用「星移」。\n"NOR); 
				if(!file = get_dir("/kungfu/skill/"+skname+"/"))
					return notify_fail(HIR+target->query("name")+"目前使的武功沒有絕招，沒法「星移」。\n"NOR); 
				skpf = file[random(sizeof(file))];

				ap=random(plvl/2)+xlvl/2;
				dp=target->query_skill("parry") / 2;
				if(dp < 1) dp = 1; 
				if (strsrch(skpf, ".c") >= 0 && ap > dp)
				{
					skpf=replace_string(skpf,".c","");
					msg = HIY "$N使出鬥轉星移的絕招"HIR"  「星移」  "HIY"，用$n"HIY"的"+to_chinese(skname)+"的絕招更快、更狠地出手！\n"NOR;
					message_combatd(msg, me, target);
/* 星移的標誌 */
					me->set_temp("murong/xingyi", 1);
					if( SKILL_D(skname)->perform_action(me, skpf) )
					{
						result = 1;
//						me->start_busy(random(2)+1);
					}
					else
					{
						result = 0;
						msg = HIG"$N一時沒捉摸到$n出手時的力道所在，使出「星移」落在了空處！\n"NOR;
						message_combatd(msg,me,target);
					}
					me->delete_temp("murong/xingyi");
				}
				else
				{
					result = 1;
					msg = HIG"$N真氣流轉不順，一時無法使出「星移」！\n"NOR;
					message_combatd(msg,me,target);
				}
				return result;
			}
		}
		else
/* 你沒有兵器 */
		{
			if( objectp(tweapon = target->query_temp("weapon")))
				return notify_fail(HIR"你和"+target->query("name")+"沒有持相同類型的兵器，沒法「星移」。\n"NOR); 
			else
			{
				if( !mapp(pre_skl = target->query_skill_prepare()) || !sizeof(pre_skl))
					sktype = "unarmed";
  			else sktype = keys(pre_skl)[random(sizeof(pre_skl))];
				
				if( me->query_skill(sktype, 1) < 120) 
					return notify_fail(HIR"你的"+to_chinese(sktype)+"修為太淺，沒法使用「星移」。\n"NOR); 

				skname = target->query_skill_mapped(sktype);
				if( skname == "xingyi-strike" ||
					skname == "canhe-finger")
					return notify_fail(HIR+target->query("name")+"深諳慕容世家的功夫，你沒法使用「星移」。\n"NOR); 
/* 對方徒手沒有perform */
				if(!file = get_dir("/kungfu/skill/"+skname+"/"))
				{
					msg = HIG"$N運起鬥轉星移，真氣流動加快，出手陡然加快！加重！！\n"NOR;
					message_combatd(msg,me,target);
					me->add_temp("apply/attack", 20);
					me->add_temp("apply/dodge", 10);
					me->add_temp("apply/defense", 10);
					COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
					COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
					me->add_temp("apply/attack", -20);
					me->add_temp("apply/dodge", -10);
					me->add_temp("apply/defense", -10);
					me->start_busy(random(3)+1);
					return 1;
				}
				skpf = file[random(sizeof(file))];

				ap=random(plvl/2)+xlvl/2;
				dp=target->query_skill("parry") / 2;
				if(dp < 1) dp = 1; 
				if (strsrch(skpf, ".c") >= 0 && ap > dp)
				{
					skpf=replace_string(skpf,".c","");
					msg = HIY "$N使出鬥轉星移的絕招"HIR"  「星移」  "HIY"，用$n的"+to_chinese(skname)+"的絕招更快、更狠地出手！\n"NOR;
					message_combatd(msg, me, target);
/* 星移的標誌 */
					me->set_temp("murong/xingyi", 1);
					if( SKILL_D(skname)->perform_action(me, skpf) )
					{
						result = 1;
//						me->start_busy(random(2)+1);
					}
					else
					{						
						result = 0;
						msg = HIG"$N一時沒捉摸到$n出手時的力道所在，使出「星移」落在了空處！\n"NOR;
						message_combatd(msg,me,target);
						return 0;
					}
					me->delete_temp("murong/xingyi");
				}
				else
				{
					result = 1;
					msg = HIG"$N真氣流轉不順，一時無法使出「星移」！\n"NOR;
					message_combatd(msg,me,target);
				}
				return result;
			}
		}
		me->start_busy(random(2)+1);
		me->delete_temp("murong/xingyi");
		return 1;
	}
}
int help (object me)
{
	write(@HELP
指令格式：perfrom | yong [<武功種類>.]<招式名稱> [<施用對象>]
          perform | yong 招式1 [<對象1>] and 招式2 [<對象2>]

    如果你所學的外功（拳腳、劍法、刀法....）有一些特殊的攻擊方
式或招式，可以用這個指令來使用，你必須先用 enable 指令指定你使
用的武功，不指定武功種類時，空手的外功是指你的拳腳功夫，使用武
器時則是兵刃的武功。空手外功的施展，必須先準備好 （prepare）你
的技能。有的特別的外功可以激發相應技能為parry來施展。

    若是你的外功中有種類不同，但是招式名稱相同的，或者不屬於拳
腳跟武器技能的武功(如輕功)，可以用 <武功>.<招式>  的方式指定，
如：

    perform sword.chan
    perform sword.chan and sword.lian

    換句話説，只要是 enable 中的武功有特殊招式的，都可以用這個
指令使用。很多武功的特殊攻擊法都非常凌厲，一旦使用，將招致對方
的拼死反擊，就是説，被攻擊方將自動開始ｋｉｌｌ你。所以要謹慎使
用哦:)。

如果你精通左右互搏，可以同時使用兩個招式攻擊同一對手或則分別
攻擊兩人。左右互搏修煉的越是精深，則成功率越高。

HELP
	);
	return 1;
}