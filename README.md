# Landing Zone

Have you ever wondered if attackers could **actually** reach a vulnerable section of code?

Landing Zone is a proof of concept tool that checks if specific user inputs can lead to execution of known-vulnerable
functions.

Example use cases:

- You are an exploit researcher trying to determine if a list of inputs can lead to a vulnerable function.
- You are a security engineer who has a vulnerable application but no patches are available. You want to know if your
  users or attackers can reach the vulnerable code.
- You are a vulnerability management practitioner who wants to **prove** that your security controls can prevent
  specific
  inputs from reaching known-vulnerable functions in an application.

This tool was created to satisfy classwork for Dakota State University's CSC-842 Security Tool Development.

Demo video: [here]()

## Prerequisites

You must have the following software installed prior to using this tool:

- Python 3 interpreter
- Pip3
- GNU Debugger

At this time we only support GNU/Linux-based operating systems.

## Usage

**1. Installation**

```bash
pip install landing-zone

landing-zone --help
```

**2. Create a config file to test your application**

```bash
vim conf.yaml
```

```yaml
# the target application
target: "testApplication/testApp"

# arguments to pass to target
arguments:
  - "1"
  - "2"
  - "3"
  - "999"

# the functions you would like to check for execution
functions:
  - "mock_CVE_2023_0466"
  - "mock_CVE_2023_0215"
  - "mock_CVE_2022_4450"
```

**3. Analyze Application**

```bash
landing-zone --conf conf.yaml
```

**Example Output**:

```
INFO:root:reading config file: 'conf.yaml'
INFO:root:examining target application: 'testApplication/testApp'

WARNING:root:Landed in target function with arguments: '1'
---------------------------
testApp.c:16:mock_CVE_2023_0466
testApp.c:34:mock1
testApp.c:63:main

...
```

## Future Work

If I were to maintain this program going forward, I would:

- support regular expressions for functions listed in conf file
- allow conditional break points (i.e. only alert if one or more conditions are true)
- support additional debuggers such as lldb and windbg
