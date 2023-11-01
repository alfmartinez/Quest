
# Quest Plugin

## Problem to solve

This plugin aims at providing easy to use objects to implement quest logic in Blueprints.
Previously, I have tried to implement quest logic with Actors and plain UObjects in blueprints, but it required a lot of wiring to handle basic use cases with delegates.
I wanted to have blueprint nodes that represent single goals that can be combined to create simple or complex quests, with execution pins to handle different situations.

## Goal as CancellableAsyncActions

The Goal class has been implemented as a CancellableAsyncAction to allow the blueprint to access execution pins linked to its dynamic multicast delegates. 
The following delegates have been implemented :
- OnGoalStarted : triggered by a call to default Start event,
- OnGoalCompleted : triggered by a call to default Complete event,
- OnGoalAborted : triggered by a call to default Abort event,
- OnGoalFailed : triggered by a call to default Fail event.
- OnGoalUpdated : triggered by a call to Update event.

Goal class can be extended to implement the specific following events : 
- Start,
- Abort,
- Fail,
- Complete.

The GetDescription method can be overriden to provide user friendly reporting on goal progress that can be used inside the UI, for example inside a Quest Log or Summary Widget.

Always remember to call the default parent event to trigger delegate execution pins.

Child Goals can be made parametrable using child variables with ExposeOnSpawn attribute set on them, and using Construct Object to pass parameters before using Start Goal.