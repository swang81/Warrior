
#pragma once

namespace Debug
{
	static void Print(const FString& Msg, const FColor& Color = FColor::MakeRandomColor(), int32 InKey = -1)
	{
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(InKey, 7.f, Color,Msg);
			/* Breakdown of the inputs:
			-1 = A unique key to prevent the same message from being added multiple times.
			    Set it to -1 if the uniqueness doesn't matter to you
			7.0f = How long to display the message, in seconds.
			FColor:The color in which it should get printed to the screen
			*/

			UE_LOG(LogTemp, Warning, TEXT("%s"), *Msg);
		}
	}
	
}
