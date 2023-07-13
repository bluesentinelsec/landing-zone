# Landing Zone

Landing Zone is a proof of concept tool that checks if specific user inputs can lead to execution of known-vulnerable
functions.

Example use cases:

- you are an exploit researcher trying to determine if a list of inputs can lead to a vulnerable function
- you are a vulnerability management practioner who wants to varify that your security controls can prevent specific
  inputs from reaching known-vulnerable functions in an application.

This tool was created to satisfy classwork for Dakota State University's CSC-842 Security Tool Development.

Demo video: [here]()

## Prerequisites

You must have the following software installed prior to using this tool:

- Python 3 interpreter
- Pip3
- GNU Debugger

## Usage

**Installation**

```bash
pip install landing-zone

landing-zone --help
```

**Create a config file to test your application**

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

**Scan Application**

```bash
landing-zone --conf conf.yaml
```

Example Output:

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

- allow breaking on functions specified as regular expressions
- allow conditional break points
- support additional debuggers such as lldb and windbg
